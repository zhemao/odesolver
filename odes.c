#include "odes.h"
#include <stdlib.h>
#include <math.h>

double rk4step(derivative f, double x, double y, double h){
	double k1 = f(x, y);
	double k2 = f(x + h/2, y + h/2 * k1);
	double k3 = f(x + h/2, y + h/2 * k2);
	double k4 = f(x + h, y + h * k3);

	return y + h/6 * (k1 + 2 * k2 + 2 * k3 + k4);
}

double * rk4(derivative f, double y0, double end, int n){
	double h = end / n;
	double * yvalues = (double *)malloc(n * sizeof(double));
	int i;

	yvalues[0] = y0;

	for(i=1; i < n; i++){
		yvalues[i] = rk4step(f, (i - 1) * h, yvalues[i-1], h);
	}

	return yvalues;
}

double * rk4sd(derivative f, double y0, double end, int n, 
					double abs_tol, double rel_tol){
	double h = end / n;
	double y, x, d0, d;
	double step1, step2;
	double xvalues[n], yvalues[n];
	double * answers = (double*)malloc(2 * n * sizeof(double*));
	int i;

	yvalues[0] = y0;
	xvalues[0] = 0;

	for(i=1; i < n; i++){
		x = xvalues[i - 1];
		y = yvalues[i - 1];
		
		step1 = rk4step(f, x, y, h);
		step2 = rk4step(f, x, y, h/2);
		step2 = rk4step(f, x + h/2, step2, h/2);

		d0 = abs(step2 - step2);
		d = rel_tol * step1 + abs_tol;

		if(d0 < d){
			xvalues[i] = x + h;
			yvalues[i] = step1;
			continue;
		}

		h = h * pow(d / d0, 0.2);

		xvalues[i] = x + h;
		yvalues[i] = rk4step(f, x, y, h);
	}

	for(i=0; i<n; i++){
		answers[2*i] = xvalues[i];
		answers[2*i + 1] = yvalues[i];
	}
	
	return answers;
}
