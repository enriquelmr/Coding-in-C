#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define m   0.05 //definimos el tamaño de los pasos del mallado en el tiempo
#define x0  -10.0//definimos el intervalo del mallado en "x", lim inf
#define x1  10.0//lim sup
#define time 23  //en el tiempo que queremos que evolucione
#define v 0.6  //la velocidad de la ecuacion de adveccion
#define cuadros 50 //numero de cuadros del gif
#define m1 0.06
;
double cond_in(int x);

int pregunta();
void writeplot(char * x);

int main() {
  int res;
 res=pregunta();
  printf("Haz seleccionado %i\n",res );




  float nm=(x1-x0)/m1;
  int n=(int)nm;// calculamos el numero de puntos en x para la malla
  float dx=m1;//definimos la misma distancia de espaciado
  float dt=m;//para espacio y para tiempo
  float ro=(dt/dx);

  float ti=time/m;//numero de pasos a dat en t
  int t=(int)ti;
//int t=5;
  double malla[t][n];
  double x[n];
  int co=(int)(x0/m1);


  /* Haciendo nuestro eje auxiliador de la graficada */
  x[0]=x0;
  for (int  i = 0; i < n; i++)
	{
		x[i+1] = x[i] + m1;
	}

for (int  i =0; i < n; i++) {
  malla[0][i]=cond_in(i-abs(co));
}
/* ahora vamos a imponer condicines en la frontera de la malla en el
eje del tiempo, i.e. la primer y ultima columna*/
for (int i = 1; i < t; i++) {
malla[i][0]=0;
malla[i][n-1]=0;
}
char *opcion;

/*A darle al mallado con toño, ya teniendo un niveles bien determinados*/

switch (res) {
  case 1:
  opcion="Euler Avanzado";
printf("Haz elegido %s\n",opcion);
      for (int i = 0; i < t-1; i++) {
           for (int j = 1; j < n-1; j++) {
                 malla[i+1][j]=malla[i][j]-(0.5*v*ro)*(malla[i][j+1]-malla[i][j-1]);
           }
      }
      break;
  case 2:
  opcion="Lax-Friedrichs";
  printf("Haz elegido %s\n",opcion);
  for (int i = 0; i < t-1; i++) {
       for (int j = 1; j < n-1; j++) {
             malla[i+1][j]=0.5*(malla[i][j+1]+malla[i][j-1])-(0.5*v*ro)*(malla[i][j+1]-malla[i][j-1]);
       }
  }
  break;

  case 3:
  opcion="Lax-Wendroff";
  printf("Haz elegido %s\n",opcion);
  for (int i = 0; i < t-1; i++) {
       for (int j = 1; j < n-1; j++) {
            malla[i+1][j]=malla[i][j]-(0.5*v*ro)*(malla[i][j+1]-malla[i][j-1])
            +0.5*pow(v*ro,2)*(malla[i][j+1]-2.0*malla[i][j]+malla[i][j-1]);
     }
  }
  break;
  case 4:
  opcion="UpWind";
printf("Haz elegido %s\n",opcion);
if(v>=0){
      for (int i = 0; i < t-1; i++) {
           for (int j = 1; j < n-1; j++) {
                 malla[i+1][j]=malla[i][j]-v*ro*(malla[i][j]-malla[i][j-1]);
           }
      }
    }
    if(v<0){
      for (int i = 0; i < t-1; i++) {
           for (int j = 1; j < n-1; j++) {
                 malla[i+1][j]=malla[i][j]-v*ro*(malla[i][j+1]-malla[i][j]);
           }
      }
    }
      break;

      default:
      printf("error vuelve a correr el programa y escoje una opcion valida \n" );
}

  writeplot(opcion);

  FILE *data_file = fopen("datos.dat", "w");

	if(data_file != NULL)
	{

	for (int  i = 0; i < t-1; i=i+10)
		{
      for (int j =0 ; j < n-1; j++) {
        fprintf(data_file, "%lf \t %lf \n", x[j], malla[i][j]);
      }

fprintf(data_file, "\n \n" );
		}


		fclose(data_file);
	}


	system("gnuplot -p plot.gnu");
  return 0;
}
double cond_in(int i){
  return exp(-pow(i*m1,2));
}

int pregunta(){
  int r;
  printf("\n \nTenemos varios metodos presiona el numero que deses ejecutar\n \n");
  printf("recuerda que las condiciones las debes de poner antes de compilar dentro del codigo\n ");
  printf("1. Euler Avanzado\n ");
  printf("2. Lax-Friedrich\n ");
  printf("3. Lax-Wendroff\n ");
  printf("4. UpWind\n ");
  scanf("%i",&r );
printf("Haz seleccionado 1er vuelta %i\n",r );
  return r;

}
void writeplot(char *opcion){

  FILE *data_file=fopen("plot.gnu","w");
  fprintf(data_file, "set terminal gif animate delay 1\nset encoding utf8\nset termoption enhanced\n" );
  fprintf(data_file, "set output '%s.gif'\n",opcion );
  fprintf(data_file, "stats 'datos.dat' using 2 name 'A' nooutput\n" );
  fprintf(data_file, "set xrange [%f:%f]\nset yrange [-1:1]\n",x0,x1 );
  fprintf(data_file, "set xlabel \"x\"\nset ylabel 'Φ' \nset title \"%s\" \n",opcion );
  fprintf(data_file, "set grid \nset zeroaxis \nset border lw 2 \n" );
  fprintf(data_file, "do for [i=0:%i]{plot 'datos.dat' index i lc 'red notitle'}\n" ,cuadros);

fclose(data_file);
 }
