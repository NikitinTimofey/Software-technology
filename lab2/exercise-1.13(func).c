#include <stdio.h>
#include <math.h>
#include <conio.h>

float func (float x, float y) {
	if (x>4,5) y=2*x;
	if ((x>=0) && (x<=4.5)) y=1-log(fabs(1-pow(x,2)));
	if (x<=0) y=pow(exp(x),-x);
	return y;
}

int main (void) {
	float f, x, y;
	printf ("Enter x:");
	scanf ("%f", &x);
	printf("\ny=%f", func(x,y));
	return 0;
}
