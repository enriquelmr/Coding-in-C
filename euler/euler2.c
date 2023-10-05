#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long N = 10; /*el número de iteraciones */

double f(double x, double y) /*x es el parámetro */
{
	return 2*(x); /*aqui va la ecuacion a resolver dy/dx = f(x,y) */	
}

int main()
{
	int i;
	double a, b, x0, y0, h, k1, k2, k3, k4, x[N], y[N];
	
	a = 0.0;
	b = 10.0;
	
	x0 = a; 
	y0 = 0.0; /*condición inicial */
	
	h = (b-a)/N;
	
	x[0] = x0;
	y[0] = y0;
	
	for(i = 0; i <= N; i++)
	{
		x[i+1] = x[i] + h;
	}	
	
	for(i = 0; i <= N; i++)
	{
		k1 = h*f(x[i], y[i]);
		k2 = h*f(x[i]+0.5*h, y[i]+0.5*k1);
		k3 = h*f(x[i]+0.5*h, y[i]+0.5*k2);
		k4 = h*f(x[i]+0.5*h, y[i]+k3);
		
		y[i+1] = y[i] + h*(2*i);
	}
	
	FILE *data_file = fopen("datos_euler.dat", "w");
	
	if(data_file != NULL)
	{

		for(i = 0; i <= N; i++)
		{

			fprintf(data_file, "\n%lf \t %lf", x[i], y[i]);
		}
		
		fclose(data_file);
	}	
	
	system("gnuplot -p euler.gnu");
}