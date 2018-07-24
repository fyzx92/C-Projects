/*Authored by Bryce Burgess
*This program is intended to see if it is possible to use chaotic systems to make precise measurements using the double pendulum as an example
*
*It will use two pendulums, with slightly different initial conditions. By taking measurements of the two pendulums, I can see how the error naturally grows. 
*From these measurements, I hope to be able to extrapolate backwards with increasing precision
*
*
*
*
*/

#include <stdio.h>
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

//F=-m1*g*cos(theta)-m2*g*cos(phi)     TODO Figure out actual equations of motion-they are more complex
//U=m1*g*r1*cos(theta)+g*(m2*r2*cos(phi)-m1*r1*cos(theta))
//T=.5*m*v1^2+.5*m*v2^2
//F=-dU/dr

///Should be equations of motion
//theta1' = omega1
//	theta1 = omega1*time + initCondition 

//theta2' = omega2
//	theta2 = omega2*time + initCondition 

//omega1'={-g*[2*m1+m2]*sin[theta1]-m2*g*sin[theta1-2*theta2]-2*sin[theta1-theta2]*m2*[omega2^2*L2+omega1^2*L1*cos(theta1-theta2)]}/{L2*[2*m1+m2-m2*cos(2*theta1-2*theta2)}
//	omega1 = ... + initCondition 

//omega2'={2*sin[theta1-theta2][omega1^2*L1(m1+m2)]+g*[m1+m2]*cos[theta1]+omega2^2*L2*m2*cos[theta1-theta2]}/{L2*[2*m1+m2-m2*cos(2*theta1-2*theta2)}
//	omega2 = ... + initCondition 


//how theta1 changes at each time step
//dTheta1(time) = time*dTheta1(time-1) + const1
int dTheta1(double theta1, double theta2, double omega1, double omega2, int dtime) {

	return omega1*dtime;  
}

//how theta2 changes at each time step
//dTheta2(time) = time*dTheta2(time-1) + const2
int dTheta2(double theta1, double theta2, double omega1, double omega2, int time) {

	return omega2*dtime;
}

//how omega1 changes at each times step
int dOmega1(double theta1, double theta2, double omega1, double omega2, int time) {
	
	return ;
}

//how omega2 changes at each times step
int dOmega2(double theta1, double theta2, double omega1, double omega2, int time) {

	return ;
}


int main (char[] args) {
	int i = 0;
	
	/// TODO Read params in from file?
	/// measurement parameters
	double time = 0;				///current time value
	double dtime = 1;				///time step size
	double measurementPeriod = 20;	///how often to take measurements
	int runtime = 72000;		///when to stop simulation
	int m = 0;
	double *measurements[runtime/measurementPeriod]; ///record measurements
	for (i = 0; i < NELEMS(measurements); i++) measurements[i] = 0;

	/// need pendulum parameters
	double theta1[runtime];
	double omega1[runtime];
	int p1Mass = 1;
	int p1Radius = 1;
	
	double theta2[runtime];
	double omega2[runtime];
	int p2mass = 1;
	int p2Radius = 1;
	
	/// Progress simulation over time
	for (time=0; time<runtime; time++) {
		theta1 += dTheta1(theta1, theta2, omega1, omega2, dtime);
		theta2 += dTheta2(theta1, theta2, omega1, omega2, dtime);
		omega1 += dOmega1(theta1, theta2, omega1, omega2, dtime);
		omega2 += dOmega2(theta1, theta2, omega1, omega2, dtime);

		if(time%measurementPeriod == 0) {
			measurements[m]+0 = &theta1;
			measurements[m]+1 = &theta2;
			measurements[m]+2 = &omega1;
			measurements[m]+3 = &omega2;
			m++;
		}
	}

	/// [ ] TODO take information from repeated measurements, try to improve accuracy
	double *errorMeasurements[runtime/measurementPeriod]; ///record measurements
	for (m = 0; m < NELEMS(measurements); m++) {
			measurements[m]+0 += rand();
			measurements[m]+1 += rand();
			measurements[m]+2 += rand();
			measurements[m]+3 += rand();
	}

}


