#ifndef __ODES_H__
#define __ODES_H__

typedef double (*derivative)(double x, double y);

double * rk4(derivative f, double y0, double end, int n);
double * rk4sd(derivative f, double y0, double end, int n, 
					double abs_tol, double rel_tol);

#endif
