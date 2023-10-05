#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long N = 1000; /*el número de iteraciones */

double f(double x,double y, double z)
{
	return z;
}
double g(double x, double y, double z) /*x es el parámetro */
      { if (x==0)
         {
	         return 0;/* code */
         }
        else{
	         return 4*(3.14159)*exp(-x*x)-(2*z)/(x); /*aqui va la ecuacion a resolver dy/dx = f(x,y) */	
            }
       }
double g1(double x, double y, double z) /*x es el parámetro */
{
	return -(2*z)/(x); /*aqui va la ecuacion a resolver dy/dx = f(x,y) */	
}

int main()
{
	int i;
	double a, b, b1, x0, y0, z0, h, h1, k1, k2, k3, k4, x[N], y[N], z[N];
	double l1, l2, l3, l4;
	double p,R;
	
	a = 0.0; /*el rango de nuestro mayado*/
	b = 1.0;
	b1=10.0;
	R=1;/*Radio de nuestro objeto*/

	x0 = 0.0;  /* condicion para r*/
	y0 = 0.0; /*condiciones iniciales pra el potencial*/
	z0=0.0; /* condiciones para l potencialauxiliar*/
	h = (b-a)/N;
	h1=(b1-b)/N;

	x[1] = x0;
	y[1] = y0;
	z[1] = z0;
	x[1]=h;
	
	
	for(i = 1; i <=N; i++)
	{
		x[i+1] = x[i] + h;
	}	
	
	for(i = 1; i <= N; i++)
	{
		k1 = h*f(x[i], y[i],z[i]);
		l1 = h*g(x[i],y[i],z[i]);
		k2 = h*f(x[i]+0.5*h, y[i]+0.5*k1,z[i]+0.5*l1);
		l2 = h*g(x[i]+0.5*h, y[i]+0.5*k1,z[i]+0.5*l1);
		k3 = h*f(x[i]+0.5*h, y[i]+0.5*k2, z[i]+0.5*l2);
		l3 = h*g(x[i]+0.5*h, y[i]+0.5*k2, z[i]+0.5*l2);
		k4 = h*f(x[i]+0.5*h, y[i]+k3, z[i]+l3);
		l4 = h*g(x[i]+0.5*h, y[i]+k3, z[i]+l3);
		
		y[i+1] = y[i] + 0.16666*(k1 + 2.0*k2 + 2.0*k3 + k4);
		z[i+1] = z[i] + 0.16666*(l1 + 2.0*l2 + 2.0*l3 + l4);
		printf("%f\n", y[i]);
	}

	/*int p1=(int)p;
	int p2=N-p1;*/
	
	double x_ext[N], y_ext[N];
     y_ext[1]=y[N+1];
     x_ext[1]=x[N+1];
     for(i=1; i<=N+1; i++)
     {
     	x_ext[i+1]=x_ext[i]+h1;
     }

	for(i=1; i <= N+1; i++)
	{
		/*k1 = h*f(x[i], y[i],z[i]);
		l1 = h*g1(x[i],y[i],z[i]);
		k2 = h*f(x[i]+0.5*h, y[i]+0.5*k1,z[i]+0.5*l1);
		l2 = h*g1(x[i]+0.5*h, y[i]+0.5*k1,z[i]+0.5*l1);
		k3 = h*f(x[i]+0.5*h, y[i]+0.5*k2, z[i]+0.5*l2);
		l3 = h*g1(x[i]+0.5*h, y[i]+0.5*k2, z[i]+0.5*l2);
		k4 = h*f(x[i]+0.5*h, y[i]+k3, z[i]+l3);
		l4 = h*g1(x[i]+0.5*h, y[i]+k3, z[i]+l3);
		
		y[i+1] = y[i] + 0.16666*(k1 + 2.0*k2 + 2.0*k3 + k4);
		z[i+1] = z[i] + 0.16666*(l1 + 2.0*l2 + 2.0*l3 + l4);*/
		y_ext[i+1]=y_ext[1]/x_ext[i+1];
		printf("%f\n", y[i]);
	}

	
	FILE *data_file = fopen("datos_potencial.dat", "w");
	
	if(data_file != NULL)
	{

		for(i = 0; i <= N; i++)
		{

			fprintf(data_file, "\n%lf \t %lf ", x[i], y[i]);
		}
		for(i = 1; i <= N+1; i++)
		{

			fprintf(data_file, "\n%lf \t %lf ", x_ext[i], y_ext[i]);
		}
		
		fclose(data_file);
	}	
	
	system("gnuplot -p potencial.gnu");
}
