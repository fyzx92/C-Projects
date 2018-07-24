/*
* Authored by Bryce Burgess
* simulate three gravitating bodies
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NELEMS(x) (sizeof(x))/(sizeof((x)[0]))

typedef struct gravityObject {
	double mass;
	double pos[3];
	double vel[3];
	double acc[3];
} gravityObject;

/// [ ] TODO how many objects to consider at once?


/// update positions and velocities of one object (a)
gravityObject updateA(gravityObject a, gravityObject b, gravityObject c, double timeInterval) {
	int i = 0;

	double x0[3] = {a.pos[1], a.pos[2], a.pos[3]};
	
	double G = 1;
	for (i = 0; i < NELEMS(a.pos); i++) {
		a.pos[i] = x0[i] + a.vel[i]*timeInterval + 0.5*a.acc[i]*pow(timeInterval,2);
		a.vel[i] = a.vel[i] + a.acc[i]*timeInterval;
		a.acc[i] = G*b.mass/(pow(a.pos[i]-b.pos[i],2)) + G*c.mass/(pow(a.pos[i]-c.pos[i],2));
	}
	return a;
}


/// initialize one gravitating object
gravityObject random_initializeGO(gravityObject a) {
	a.mass = 10*rand();
//	a.mass = 10;

	a.pos[0] = 100*rand();
	a.pos[1] = 100*rand();
	a.pos[2] = 100*rand();
//	a.pos[0] = 100*rand();
//	a.pos[1] = 100*rand();
//	a.pos[2] = 100*rand();

	a.vel[0] = 100*rand();
	a.vel[1] = 100*rand();
	a.vel[2] = 100*rand();
//	a.vel[0] = 0;
//	a.vel[1] = 0;
//	a.vel[2] = 0;

	a.acc[0] = 0;
	a.acc[1] = 0;
	a.acc[2] = 0;

	return a;
}


void printPositions(gravityObject m1, gravityObject m2, gravityObject m3) {
	printf("m1 coordinates are %f, %f, %f \n", m1.pos[0], m1.pos[1], m1.pos[2]);
	printf("m2 coordinates are %f, %f, %f \n", m2.pos[0], m2.pos[1], m2.pos[2]);
	printf("m3 coordinates are %f, %f, %f \n", m3.pos[0], m3.pos[1], m3.pos[2]);
	printf("\n\n\n");
}

int main() {
	/// declare gravitating objects
	gravityObject *pm1;
	pm1 = malloc(sizeof(gravityObject));
	gravityObject m1 = *pm1;

	gravityObject *pm2;
	pm2 = (gravityObject *) malloc(sizeof(gravityObject));
	gravityObject m2 = *pm2;
	
	gravityObject *pm3;
	pm3 = (gravityObject *) malloc(sizeof(gravityObject));
	gravityObject m3 = *pm3;

	printf("objects created\n");

	/// randomly initialize gravitating objects
	m1 = random_initializeGO(m1);
	m2 = random_initializeGO(m2);
	m3 = random_initializeGO(m3);

	printf("objects initiated\n");
	
	/// run simulation
	int runtime = 50;
	double t = 0;
	double timeInterval = 0.1;
	printf("simulation starting\n");
	for (t = 0 ; t < runtime; t += timeInterval) {
		printPositions(m1, m2, m3);

		/// update position of each object (first one is being updated)
		m1 = updateA(m1, m2, m3, timeInterval);
		m2 = updateA(m2, m3, m1, timeInterval);
		m3 = updateA(m3, m1, m2, timeInterval);
		/// [ ] TODO plot position
	}

	free(pm1);
	free(pm2);
	free(pm3);
}
