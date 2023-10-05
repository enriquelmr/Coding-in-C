#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long N = 100; /*el número de iteraciones */

double f(double x,double y, double z)
{
	return z 
}
double g(double x, double y, double z) /*x es el parámetro */
{
	return 4*(3.14159)-(2*z)/(x); /*aqui va la ecuacion a resolver dy/dx = f(x,y) */	
}

int main()
{
	int i;
	double a, b, x0, y0, h, k1, k2, k3, k4, x[N], y[N], z[N];
	double l1, l2, l3, l4;
	
	a = 0.0;
	b = 5;
	
	x0 = a;  /* condicion para r*/
	y0 = 0.0; /*condiciones iniciales pra el potencial*/
	z0=0.0; /* condiciones para l potencialauxiliar*/
	h = (b-a)/N;
	
	x[0] = x0;
	y[0] = y0;
	z[0] = z0;
	
	for(i = 0; i <= N; i++)
	{
		x[i+1] = x[i] + h;
	}	
	
	for(i = 0; i <= N; i++)
	{
		k1 = h*f(x[i], y[i],z[i]);
		l1 = h*g(x[i],y[i],z[i]);*
		k2 = h*f(x[i]+0.5*h, y[i]+0.5*k1,z[i]+0.5*l1);
		l2 = h*g(x[i]+0.5*h, y[i]+0.5*k1,z[i]+0.5*l1);
		k3 = h*f(x[i]+0.5*h, y[i]+0.5*k2, z[i]+0.5*l2);
		l3 = h*g(x[i]+0.5*h, y[i]+0.5*k2, z[i]+0.5*l2);
		k4 = h*f(x[i]+0.5*h, y[i]+k3, z[i]+l3);
		l4 = h*g(x[i]+0.5*h, y[i]+k3, z[i]+l3);
		
		y[i+1] = y[i] + 0.16666*(k1 + 2.0*k2 + 2.0*k3 + k4);
		z[i+1] = z[i] + 0.16666*(l1 + 2.0*l2 + 2.0*l3 + l4);
	}
	
	FILE *data_file = fopen("datos_runge.dat", "w");
	
	if(data_file != NULL)
	{

		for(i = 0; i <= N; i++)
		{

			fprintf(data_file, "\n%lf \t %lf", x[i], y[i]);
		}
		
		fclose(data_file);
	}	
	
	system("gnuplot -p runge.gnu");
}
