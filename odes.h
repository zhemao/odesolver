#ifndef __ODES_H__
#define __ODES_H__

/* functions of type derivative should take x and y 
 * and return dy/dx evaluated at that point */ 
typedef double (*derivative)(double x, double y);

/* solve ode using an rk4 algorithm 
 * f is the derivative function 
 * end is the maximum x value
 * n is the number of steps to take 
 * returns an array of size n containing the y values */
double * rk4(derivative f, double y0, double end, int n);

/* solve ode using an rk4 algorithm and step doubling for adaptive stepping
 * the first four arguments are the same as rk4, abs_tol and rel_tol 
 * define relative and absolute tolerances 
 * returns an array of size 2n 
 * the even elements are the x values
 * the odd elements are the y values */
double * rk4sd(derivative f, double y0, double end, int n, 
					double abs_tol, double rel_tol);

#endif
