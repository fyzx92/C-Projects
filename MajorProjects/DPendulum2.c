/*
*
* Authored by Bryce Burgess
*
* Angle implementation of double pendulum
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI = 3.14159265358979323846

typedef struct pendulum {
	double mass;
	double radius;
	double pivot[2];
	double theta;
	double omega;
	double alpha;
	double pos[2];
} pendulum;

/*/////////////////////////////////////////////////////////
TESTS
/////////////////////////////////////////////////////////*/
// [ ] TODO test max length
void test_pendulum_length() {
	
}
// [ ] TODO test angle range
// [ ] TODO test consistency of constant params
// [ ] TODO test position calculation
/*/////////////////////////////////////////////////////////
END TESTS
/////////////////////////////////////////////////////////*/

initialize_pendulum_random(){}
initialize_pendulum_simple(pendulum p){
	p.mass = 1;
	p.radius = 1;
	p.theta = PI/4;
	p.omega = 0;
	p.alpha = 0;
	p.pos[0] = p.pivot[0] + p.radius*p.cos(p.theta);
	p.pos[1] = p.pivot[1] + p.radius*p.sin(p.theta);

}

ang_acc1(pendulum p1, pendulum p2){
	double num1 = 
	double num2 = 
	double num3 = 
	double den = 
	alpha1 = ;
	return alpha1;
}

ang_acc2(pendulum p1, pendulum p2){
	double num1 = 
	double num2 = 
	double num3 = 
	double den = 
	alpha2 = ;
	return alpha2;
}

Runge_Kutta (double dt, double *(ang_acc))() {
	k1 = dt*ang_acc;
	k2 = dt*;
	k3 = dt*;
	k4 = dt*;
	y = (k1 +2*k2 + 2*k3 + k4)/6.0
	return y;
}

void calc_position(pendulum p) {
	p.pos[0] = p.pivot[0] + p.length*sin(p.theta)
	p.pos[1] = p.pivot[1] + p.length*cos(p.theta)
}

int main() {

	/// pendulum declaration and initialization
	pendulum *pp1;
	pp1 = malloc(sizeof(pendulum));
	p1 = *pp1;
	p1.pivot[0] = 0;
	p1.pivot[1] = 0;
	p1 = initialize_pendulum_simple(p1)

	pendulum *pp2;
	pp2 = malloc(sizeof(pendulum));
	p2 = *pp2;
	p2.pivot[0] = p1.pos[0];
	p2.pivot[1] = p1.pos[1];
	p2 = initialize_pendulum_simple(p2)

}
