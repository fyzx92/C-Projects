/*
* Authored by Bryce Burgess
* different integration methods
*/

#include <stdio.h>
#include <math.h>
#define NELEMS(x) (sizeof(x)/(sizeof(x)[0])

/// known function is input
double RKintegration(double t, double y0, double (*ydot)(double, double)){

	double dt = 0.01;
	double y = y0;
	bool integrating = true;
	double k[4];

	k[0] = dt*ydot(t,y);
	k[1] = dt*ydot(t + dt/2.0, y+k1/2.0);
	k[2] = dt*ydot(t + dt/2.0, y+k2/2.0);
	k[3] = dt*ydot(t+dt, y+k3);

	y = y + (k[0] + 2.0*k[1] + 2.0*k[2] +k[3])/6.0;

	return y;
}


/// input from momentary data points
double RKintegration(double t, double y0, double ydot[]){

	double dt = 0.01;
	double y = y0;
	bool integrating = true;
	double k[4];

	k[0] = dt*ydot(t,y);
	k[1] = dt*ydot(t + dt/2.0, y+k1/2.0);
	k[2] = dt*ydot(t + dt/2.0, y+k2/2.0);
	k[3] = dt*ydot(t+dt, y+k3);

	y = y + (k[0] + 2.0*k[1] + 2.0*k[2] +k[3])/6.0;

	return y;
}


double Euler_integration(double dt, double y, double ydot[]) {

	for (int i = 0, i<NELEMS(ydot), i++) {
		y += ydot[i]*pow(dt,i)/((double)factorial(i));
	}
	return y;
}

int factorial(int n) {
	int out = 1;
	for (int i = 1; i<=n; i++) {
		out *= i;
	}

	if (n < 0) {
		out = -1;
		printf("Error: input value was negative")
	}
	
	return out;
}
