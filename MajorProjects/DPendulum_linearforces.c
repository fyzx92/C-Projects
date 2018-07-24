/*
* Authored by Bryce Burgess
* Simulate a double pendulum
*/

// [x] record/print values
// [ ] TODO read params from file?
// [ ] TODO write to file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct pendulum {
	double pivot[2];
	double mass;
	double theta;
	double theta_p;
	double radius;
	double pos[2];
	double vel[2];
	double acc[2];
} pendulum;



/// this is in radians
pendulum calcAngle(pendulum p) {
	/// calculate angle
	p.theta = atan(p.pos[0]/p.pos[1]);
	
	/// account for ambiguous cases
	if (p.pos[1] == 0 && p.pos[0]>=0) p.theta = PI/2.0;
	else if(p.pos[1] == 0 && p.pos[0]<0) p.theta = -PI/2.0;

	return p;
}
pendulum calcPos(pendulum p) {
	p.pos[0] = p.pivot[0] + p.radius*sin(p.theta);
	p.pos[1] = p.pivot[1] + p.radius*cos(p.theta);
	return p;
}

/// calculate the forces on pendulum 1 in x direction
double F1x(double theta1, double theta2, double m1, double m2, double g) {
	double f1x = (m1 + m2)*g*sin(theta1) - m2*g*sin(theta2);
	return f1x;
}

/// calculate the forces on pendulum 1 in y direction
double F1y(double theta1, double theta2, double m1, double m2, double g) {
	double f1y = -m1*g + (m1 + m2)*g*cos(theta1) - m2*g*cos(theta2);
	return f1y;
}

/// calculate the forces on pendulum 2 in x direction
double F2x(double theta2, double m2, double g) {
	double f2x = m2*g*sin(theta2); 
	return f2x;
}

/// calculate the forces on pendulum 2 in y direction
double F2y(double theta2, double m2, double g) {
	double f2y = -m2*g + m2*g*cos(theta2); 
	return f2y;
}

int main() {

	// simulation parameters
	double g = 1;

	// create and initialize pendulums
	pendulum *pp1;
	pp1 = malloc(sizeof(pendulum));
	pendulum p1 = *pp1;

	p1.theta = PI/6;
	p1.theta_p = 0;
	p1.radius = 1;
	p1.mass = 1;
	p1.pivot[0] = 0;
	p1.pivot[1] = 0;

	p1.acc[0] = 0;
	p1.acc[1] = 0;
	p1.vel[0] = p1.theta_p*p1.radius*cos(p1.theta);
	p1.vel[1] = p1.theta_p*p1.radius*sin(p1.theta);
	p1.pos[0] = p1.radius*sin(p1.theta);
	p1.pos[1] = p1.radius*cos(p1.theta);





	pendulum *pp2;
	pp2 = malloc(sizeof(pendulum));
	pendulum p2 = *pp2;

	p2.theta = PI/6;
	p2.theta_p = 0;
	p2.radius = 1;
	p2.mass = 1;
	p2.pivot[0] = p1.pos[0];
	p2.pivot[1] = p1.pos[1];

	p2.acc[0] = 0;
	p2.acc[1] = 0;
	p2.vel[0] = p2.theta_p*p2.radius*cos(p2.theta);
	p2.vel[1] = p2.theta_p*p2.radius*sin(p2.theta);
	p2.pos[0] = p1.pos[0] + p2.radius*sin(p2.theta);
	p2.pos[1] = p1.pos[1] + p2.radius*cos(p2.theta);


//	printf("a1 is (%f, %f)\t", p1.acc[0], p1.acc[1]);
//	printf("a2 is (%f, %f)\n\n", p2.acc[0], p2.acc[1]);
//	printf("v1 is (%f, %f)\t", p1.vel[0], p1.vel[1]);
//	printf("v2 is (%f, %f)\n\n", p2.vel[0], p2.vel[1]);
//	printf("x1 is at (%f, %f)\t", p1.pos[0], p1.pos[1]);
//	printf("x2 is at (%f, %f)\n\n\n", p2.pos[0], p2.pos[1]);


	printf("masses and states initialized\n starting simulation\n\n");



	// run simulation
	int time = 5;
	double t = 0;
	double dt = 0.01;
	for(t = 0; t < time; t += dt) {

		// Calculate acceleration
		p1.acc[0] = F1x(p1.theta, p2.theta, p1.mass, p2.mass, g)/p1.mass;
		p1.acc[1] = F1y(p1.theta, p2.theta, p1.mass, p2.mass, g)/p1.mass;

		p2.acc[0] = p1.acc[0] + F2x(p2.theta, p2.mass, g)/p2.mass;
		p2.acc[1] = p1.acc[1] + F2y(p2.theta, p2.mass, g)/p2.mass;

//		printf("a1 is (%f, %f)\t", p1.acc[0], p1.acc[1]);
//		printf("a2 is (%f, %f)\n\n", p2.acc[0], p2.acc[1]);





		// Calculate velocity
		p1.vel[0] += p1.acc[0]*dt;
		p1.vel[1] += p1.acc[1]*dt;
		
		p2.vel[0] += p1.vel[0] + p2.acc[0]*dt;
		p2.vel[1] += p1.vel[1] + p2.acc[1]*dt;

//		printf("v1 is (%f, %f)\t", p1.vel[0], p1.vel[1]);
//		printf("v2 is (%f, %f)\n\n", p2.vel[0], p2.vel[1]);





		// Calculate position
		p1.pos[0] += p1.vel[0]*dt + 0.5*p1.acc[0]*dt*dt;
		p1.pos[1] += p1.vel[1]*dt + 0.5*p1.acc[1]*dt*dt;

		p2.pos[0] += p1.pos[0] + p2.vel[0]*dt + 0.5*p2.acc[0]*dt*dt;
		p2.pos[1] += p1.pos[1] + p2.vel[1]*dt + 0.5*p2.acc[1]*dt*dt;
		
		// Update angle
		p1 = calcAngle(p1);
		p2 = calcAngle(p2);

		// recalculate position
		p1 = calcPos(p1);
		p2 = calcPos(p2);

//		printf("x1 is at (%f, %f)\t", p1.pos[0], p1.pos[1]);
		printf("x2 is at (%f, %f)\n\n\n", p2.pos[0], p2.pos[1]);
	}

	free(pp1);
	free(pp2);

}
