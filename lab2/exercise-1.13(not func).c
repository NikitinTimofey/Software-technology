#include <stdio.h> 
#include <math.h> 
#include <conio.h> 
 
int main (void) { 
 float x, y;    
 printf ("Enter x:"); 
 scanf ("%f", &x); 
 if (x>4,5) y=2*x; 
 if ((x>=0) && (x<=4.5)) y=1-log(fabs(1-pow(x,2))); 
 if (x<=0) y=pow(exp(x),-x);  
 printf("\ny=%f", y); 
 return 0; 
}