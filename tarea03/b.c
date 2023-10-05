#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long N = 300; /*el número de iteraciones */
#define sigma  1
#define r0  50
#define phi0  1
#define pi  3.14159

double f(double x, double y, double z) /*x es el parámetro */
      { if (x==0)
         {
	         return 0;/* code */
         }
        else{

	         return (1/pow(x,2))*(1-y)-(3/x)*z+0.25*((z*z)/y)-16.0*pi*z*((pow((x-r0),2)*phi0*phi0)/pow(sigma,2))*exp(-2.0*pow((x-r0),2)/pow(sigma,2)); /*aqui va la ecuacion a resolver dy/dx = f(x,y) */
            }
       }

double g(double x,double y, double z)
       {
       	return z;
       }
int main()
{
	int i;
	double a, b,  x0, y0,z0, h,  k1, k2, k3, k4, x, y,z;
double l1, l2, l3, l4;

	a = 0.0; /*el rango de nuestro mayado*/

	b=1000.0;

  h=(b-a)/N;

	x0 = 0.0;  /* condicion para r*/
	y0 = 1.0; /*condiciones iniciales pra el potencial*/
  z0=0.0;

	FILE *data_file = fopen("datosb.dat", "w");


	for(i = 1; i <= N; i++)
	{
    fprintf(data_file, "%lf \t %lf \n", x0, y0);

		k1 = h*g(x0, y0,z0);
    l1 = h*f(x0,y0,z0);
		k2 = h*g(x0+0.5*h, y0+0.5*k1,z0+0.5*l1);
   l2 = h*f(x0+0.5*h, y0+0.5*k1,z0+0.5*l1);
		k3 = h*g(x0+0.5*h, y0+0.5*k2,z0+0.5*l2);
	l3 = h*f(x0+0.5*h, y0+0.5*k2, z0+0.5*l2);
		k4 = h*g(x0+0.5*h, y0+k3, z0+l3);
	l4 = h*f(x0+0.5*h, y0+k3, z0+l3);
    x = x0 + h;
		y = y0 + 0.16666*(k1 + 2.0*k2 + 2.0*k3 + k4);
		z= z0 + 0.16666*(l1 + 2.0*l2 + 2.0*l3 + l4);



		x0=x;
		y0=y;
   z0=z;
}
				fclose(data_file);


	system("gnuplot -p B.gnu");
}
