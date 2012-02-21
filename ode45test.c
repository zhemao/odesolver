#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "odes.h"

double deriv(double x, double y){
	return y;
}

int main(void){
	double * answers;
	int i;
	double x, y;

	answers = ode45(deriv, 1, 10, 1000, 0.1, 0.1);

	for(i=0; i<1000; i++){
		x = answers[2*i];
		y = answers[2*i + 1];
		printf("%f\t%f\n", x, y);
	}

	free(answers);

	return 0;
}
