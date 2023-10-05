#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long m=2.0;
const double  h=0.001;

double A (double r);
double B (double r);
double F (double r);
double approxdif(double r);



int main() {
  /* codigo para encntrar horizontes aparentes en simetria esférica */
   double d, r0, r00,r, t, err,c;

   err=0.0001;

   t=0.0;
   r0=4.0*m; //condición incial
   r00=1.0*m;
   d=1.0;
/*  printf("%lf\n",r0);
//for(int i; i<5;i++){
   while (err<d) {
    r=r0-F(r0,t)/approxdif(r0,t);
    d=fabs(r-r0);
    r0=r;
     //printf("%lf\n",pow(A(r0,t),-0.5));
    //printf("%lf\n",F(r0+i*h,t));
    printf("%lf\n",F(r0,t));
    printf("%lf\n",approxdif(r0,t));


  }*/

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
     return 1/(1.0-2.0*m/r);
     //return pow(1.0-0.5*m/r,4);
}
double B(double r){
    return 1.0;
    //return pow(1.0-0.5*m/r,4);
}
double F(double r){
      return (1/A(r))*pow((2/r),2);

}
double approxdif(double r0){
  return (F(r0+h)-F(r0))/h;
}
