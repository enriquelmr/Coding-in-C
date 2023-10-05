
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
int n=10;
float a,b,h,y[n],y0,x[n];

a=0.0;
b=10.0;
y0=0.;
y[0]=y0;
x[0]=a;
h=(b-a)/n;
int i=0;

for(  i=1;i<=n;i++){
   y[i]=y[i-1]+h*(2*i);
   
 }
for (  i=1; i<=n; i++)
{
	x[i]=x[i-1]+h;
}
 
	FILE *data_file = fopen("datos_euler.dat", "w");
	
	if(data_file != NULL)
	{

		for(i = 0; i <= n; i++)
		{

			fprintf(data_file, "\n%lf \t %lf", x[i], y[i]);
		}
		
		fclose(data_file);
	}	
	
	system("gnuplot -p euler.gnu");
}
