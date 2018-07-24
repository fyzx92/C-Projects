/*Authored by Bryce Burgess
*This program is intended to see if it is possible to use chaotic systems to make precise measurements using the double pendulum as an example
*
*It will use two pendulums, with slightly different initial conditions. By taking measurements of the two pendulums, I can see how the error naturally grows. 
*From these measurements, I hope to be able to extrapolate backwards with increasing precision
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

int main () {
	/// TODO Read params in from file?
	/// measurement parameters
	double time = 0;				///current time value
	double dtime = 0.1;				///time step size
	double g = 9.8;
	double measurementPeriod = 20;	///how often to take measurements
	double runtime = 72000;		///when to stop simulation
//	double measurements[(int)(runtime/measurementPeriod)]; ///record measurements
//	for (i = 0; i < NELEMS(measurements); i++) measurements[i] = 0;

	/// need pendulum parameters
	double p1Radius, theta1, omega1, p1mass;
	double p2Radius, theta2, omega2, p2mass;

	scanf("Enter the length of pendulum 1 %lf \n", &p1Radius);
	scanf("Enter the starting angle of pendulum 1 %lf \n", &theta1);
	scanf("Enter the starting angular velocity of pendulum 1 %lf \n", &omega1);
	scanf("Enter the mass of pendulum 1 %lf \n", &p1mass);
	double v1  = omega1*p1Radius;
	double vx1 = -v1*sin(theta1); //TODO how to constrain velocities?
	double vy1 =  v1*cos(theta1);
	double x1  = p1Radius*sin(theta1); //[runtime];
	double y1  = p2Radius*cos(theta1); //[runtime];
	
	scanf("Enter the length of pendulum 2 %lf \n", &p2Radius);
	scanf("Enter the starting angle of pendulum 2 %lf \n", &theta2);
	scanf("Enter the starting angular velocity of pendulum 2 %lf \n", &omega2);
	scanf("Enter the mass of pendulum 1 %lf \n", &p2mass);
	double v2  = omega2*p2Radius;
	double vx2 = -v2*sin(theta2) - vx1;
	double vy2 =  v2*cos(theta2) + vy1;
	double x2  = p2Radius*sin(theta2) + x1;
	double y2  = p2Radius*cos(theta2) + y1;
	
	/// TODO Duplicate initial pendulum with small error

	///Simulation
	double F1x = 0, F1y = 0, F2x = 0, F2y = 0;	
	for (time = 0; time < runtime; time+=dtime) {
		F1x = p2mass*g*sin(theta2) - (p1mass+p2mass)*g*sin(theta1);
		F1y = -p1mass*g - p2mass*g*cos(theta2) + (p1mass+p2mass)*g*cos(theta1);
		F2x = -p2mass*g*sin(theta2);
		F2y = -p2mass*g + p2mass*g*cos(theta2);

		x1 = 0.5*F1x/p1mass*dtime*dtime + vx1*dtime + x1;
		y1 = 0.5*F1y/p1mass*dtime*dtime + vy1*dtime + y1;
		x2 = 0.5*F2x/p1mass*dtime*dtime + vx2*dtime + x2;
		y2 = 0.5*F2y/p1mass*dtime*dtime + vy2*dtime + y2;
	
		theta1 = asin(x1/y1);
		theta2 = asin(x2/y2);
	}
}
