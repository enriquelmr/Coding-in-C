#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long m=1.0;
const double  h=0.0000001;

double A (double r);
double B (double r);
double F (double r);

double DB(double r);


int main() {
  /* codigo para encntrar horizontes aparentes en simetria esférica */
   double d, r0, r00,r, t, err,c;

   err=0.00001;

   t=0.0;
   r0=1.3*m; //condición incial
   r00=0.2*m;
   d=1.0;

    if (F(r0)*F(r00)  >= 0) {
      printf("error, malas condiciones iniciales" );
    }

  c=(r0+r00)/2;
  if (F(c)==0) {
    printf("%lf\n, el punto medio es la raiz",c );
  }
  else{
      while (fabs(F(c))>err) {
            if (F(r0)*F(c)<0) {
              r00=c;
            }
            else{
              r0=c;
            }
            c=(r0+r00)/2;

      }
}
   printf("el Horizonte aparente esta en r=%lf\n",c);
   printf("para M=%ld\n",m );

  return 0;
}
double A(double r){
    // return 1/(1.0-2.0*m/r);
     return pow(1.0-0.5*m/r,4);
}
double B(double r){
    //eturn 1.0;
    return pow(1.0-0.5*m/r,4);
}
double F(double r){
      return (1/sqrt(A(r)))*((2/r)-DB(r)/B(r));

}
double DB(double r){
  //return (B(r+h)-B(r))/h;
  return 2.0*(1/(r*r))*m*pow(1.0-0.5*m/r,3);
}
