#include "odes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double deriv(double x, double y){
	return y;
}

int main(void){
	double * answer = rk4(deriv, 1, 10, 1000);
	int i;

	for(i=0; i < 1000; i++){
		double x = i / 100.0;
		double y = exp(x);
		double ycalc = answer[i];
		double relerr = (y - ycalc) / y;
		printf("%f\t%f\t%f\t%f\n", x, ycalc, y, relerr);
	}

	free(answer);

	return 0;
}
