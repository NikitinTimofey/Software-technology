#include <stdio.h> 
#include <math.h> 
#include <conio.h> 
 
int main (void) { 
 float x, F, a, b, c; 
  
 printf ("Enter x:"); 
 scanf ("%f", &x); 
 printf ("Enter a:"); 
 scanf ("%f", &a); 
 printf ("Enter b:"); 
 scanf ("%f", &b); 
 printf ("Enter c:"); 
 scanf ("%f", &c); 
 
 if ((x-1<0) && (b-x!=0)) F=a*x*x+b; 
 if ((x-1>0) && (b+x==0)) F=(x-a)/x; 
  else F=x/c; 
 printf("\ny=%f", F); 
 
 return 0; 
}
