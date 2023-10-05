#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long N = 30000; /*el número de iteraciones */
#define sigma  100.0
#define r0  0.1
#define phi0  0.05
#define pi  3.14159

double f(double x, double y) /*x es el parámetro */
      { if (x==0)
         {
	         return 0;/* code */
         }
        else{

	         return ((y/x)*(1.0-y))+16.0*pi*x*y*((pow((x-r0),2)*phi0*phi0)/pow(sigma,2))*exp(-2.0*pow((x-r0),2)/pow(sigma,2)); /*aqui va la ecuacion a resolver dy/dx = f(x,y) */
            }
       }


int main()
{
	int i;
	double a, b,  x0, y0, h,  k1, k2, k3, k4, x, y;


	a = 0.0; /*el rango de nuestro mayado*/

	b=1000.0;

  h=(b-a)/N;

	x0 = 0.0;  /* condicion para r*/
	y0 = 1.0; /*condiciones iniciales pra el potencial*/


	FILE *data_file = fopen("datos.dat", "w");


	for(i = 1; i <= N; i++)
	{
    fprintf(data_file, "%lf \t %lf \n", x0, y0);

		k1 = h*f(x, y);

		k2 = h*f(x0+0.5*h, y0+0.5*k1);

		k3 = h*f(x0+0.5*h, y0+0.5*k2);

		k4 = h*f(x0+0.5*h, y0+k3);

    x = x0 + h;
		y = y0 + 0.16666*(k1 + 2.0*k2 + 2.0*k3 + k4);

		x0=x;
		y0=y;

}
				fclose(data_file);


	system("gnuplot -p A.gnu");
}
