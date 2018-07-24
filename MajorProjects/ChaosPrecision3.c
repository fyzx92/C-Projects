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

typedef struct pendulum {
	double mass;
	double length;
	double theta;
	double omega;
	double pos[2];
	double vel[3];
	double acc[3];
	double updatePos();
	double updateVel();
	double updateAcc();
} pendulum;

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
	pendulum *p1;
	p1 = malloc(sizeof(pendulum))
	pendulum *p2;
	p2 = malloc(sizeof(pendulum))

	scanf("Enter the length of pendulum 1 %lf \n", &p1.length);
	scanf("Enter the starting angle of pendulum 1 %lf \n", &p1.theta);
	scanf("Enter the starting angular velocity of pendulum 1 %lf \n", &p1.omega);
	scanf("Enter the mass of pendulum 1 %lf \n", &p1.mass);

	p1.vel[2] = p1.omega*p1.length;
	p1.vel[0] = -p1.vel[0]*sin(p1.theta); //TODO how to constrain velocities?
	p1.vel[1] =  p1.vel[0]*cos(p1.theta);

	p1.pos[0]  = p1.length*sin(p1.theta); //[runtime];
	p1.pos[1]  = p1.length*cos(p1.theta); //[runtime];

	p1.acc[0] = 0;
	p1.acc[1] = 0;
	p1.acc[2] = 0;
	
	scanf("Enter the length of pendulum 2 %lf \n", &p2.length);
	scanf("Enter the starting angle of pendulum 2 %lf \n", &p2.theta);
	scanf("Enter the starting angular velocity of pendulum 2 %lf \n", &p2.omega);
	scanf("Enter the mass of pendulum 1 %lf \n", &p2.mass);

	p2.vel[2] = p2.omega*p2.length;
	p2.vel[0] = -p2.vel[2]*sin(p2.theta) - p2.vel[0];
	p2.vel[1] =  p2.vel[2]*cos(p2.theta) + p1.vel[1];

	p2.pos[0] = p2.length*sin(p2.theta) + p1.pos[0];
	p2.pos[1] = p2.length*cos(p2.theta) + p1.pos[1];

	p2.acc[0] = 0;
	p2.acc[1] = 0;
	p2.acc[2] = 0;
//////////////////// INITIALIZATION FINISHED /////////////////////	

	///Simulation
	double F1x = 0, F1y = 0, F2x = 0, F2y = 0;	
	for (time = 0; time < runtime; time+=dtime) {
		F1x = p2.mass*g*sin(p2.theta) - (p1.mass+p2.mass)*g*sin(p1.theta);
		F1y = -p1.mass*g - p2.mass*g*cos(p2.theta) + (p1.mass+p2.mass)*g*cos(p1.theta);
		F2x = -p2.mass*g*sin(p2.theta);
		F2y = -p2.mass*g + p2.mass*g*cos(p2.theta);

		p1.vel[2] = ;
		p1.vel[0] = F1x/p1.mass*dtime;
		p1.vel[1] = F1y/p1.mass*dtime;
		p2.vel[2] = ;
		p2.vel[0] = F2x/p2.mass*dtime;
		p2.vel[1] = F2y/p2.mass*dtime;

		p1.pos[0] = 0.5*F1x/p1.mass*dtime*dtime + p1.vel[0]*dtime + p1.pos[0];
		p1.pos[1] = 0.5*F1y/p1.mass*dtime*dtime + p1.vel[1]*dtime + p1.pos[1];
		p2.pos[0] = 0.5*F2x/p2.mass*dtime*dtime + p2.vel[0]*dtime + p2.pos[0];
		p2.pos[1] = 0.5*F2y/p2.mass*dtime*dtime + p2.vel[1]*dtime + p2.pos[1];
	
		p1.theta = asin(p1.pos[0]/p1.pos[1]);
		p1.theta = asin(p2.pos[0]/p2.pos[1]);

		p1.omega = ;
		p2.omega = ;
	}

	free(p1)
	free(p2)
}
