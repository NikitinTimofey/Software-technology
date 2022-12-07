#include <stdio.h>
#include <math.h>
#include <conio.h>
float func (float x, float F, float a, float b, float c) {
 F=x/c;
 if ((x-1<0) && (b-x!=0)) F=a*x*x+b;
 if ((x-1>0) && (b+x==0)) F=(x-a)/x;
 return F;
}
int main (void) {
 float f, x, F, a, b, c;
 printf ("Enter x:");
 scanf ("%f", &x);
 printf ("Enter a:");
 scanf ("%f", &a);
 printf ("Enter b:");
 scanf ("%f", &b);
 printf ("Enter c:");
 scanf ("%f", &c);
 printf("\ny=%f", func(x,F,a,b,c));
 return 0;
}
