#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define m   0.1 //definimos el tamaño de los pasos del mallado
#define x0  -20.0//definimos el intervalo del mallado en "x", lim inf
#define x1  20.0//lim sup
#define time 100  //en el tiempo que queremos que evolucione
#define ro  1  //toma tu condicion de rho

double cond_in(int x);
double cond_in2(int x);


int main() {

  float nm=(x1-x0)/m;
  int n=(int)nm;// calculamos el numero de puntos en x para la malla
  float dx=m;//definimos la misma distancia de espaciado
  float dt=m;//para espacio y para tiempo
  float rho=ro*ro;

  float ti=time/m;//numero de pasos a dat en t
  int t=(int)ti;
//int t=5;
  double malla[t][n];
  double x[n];
  int co=(int)(x0/m);


  /* Haciendo nuestro eje auxiliador de la graficada */
  x[0]=x0;
  for (int  i = 0; i < n; i++)
	{
		x[i+1] = x[i] + m;
	}
/* Poniendo condiciones iniciales para los dos primeros niveles del mallado
*/

for (int  i =0; i < n; i++) {
  malla[0][i]=cond_in(i-abs(co));
}

for (int  i = 1; i < n-1; i++) {
  malla[1][i]=malla[0][i]+dt*cond_in2(i-abs(co))+0.5*rho*(malla[0][i+1]-2*malla[0][i]+malla[0][i-1]);
}
/*A darle al mallado con toño, ya teniendo dos niveles bien determinados*/
int jaux=2;//Definimos un contador auxiliar ya que el mallado se ira reduciendo
//con tal de evitar problemas a la frontera
for (int i = 1; i < t-1; i++) {
  for (int j = jaux; j < n-jaux; j++) {
    malla[i+1][j]=2*malla[i][j]-malla[i-1][j]+rho*(malla[i][j+1]-2*malla[i][j]+malla[i][j-1]);
  }
  jaux=jaux+1;
}
 int jaux2=0;
  FILE *data_file = fopen("datos.dat", "w");

	if(data_file != NULL)
	{

	for (int  i = 0; i < t-1; i++)
		{
      for (int j = jaux2; j < n-jaux2; j++) {
        fprintf(data_file, "%lf \t %lf \n", x[j], malla[i][j]);
      }
      jaux2=jaux2+1;
fprintf(data_file, "\n \n" );
		}


		fclose(data_file);
	}

	system("gnuplot -p onda.gnu");
  return 0;
}
double cond_in(int i){
  return exp(-(i-(-4))*m*(i-(-4))*m)+exp(-(i+(-4))*m*(i+(-4))*m);//cos((i-(-3))*m)+cos((i+(-3))*m);
}
double cond_in2(int i){
  return -2*(i-(-4))*m*exp(-(i-(-4))*m*(i-(-4))*m)+2*(i+(-4))*m*exp(-(i+(-4))*m*(i+(-4))*m);//-sin((i-(-3))*m)+sin((i+(-3))*m);
}
