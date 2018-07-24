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
	double pivot;
	double theta;
	double omega;
	double alpha;
	double pos[2];
	double vel[2];
	double acc[2];
} pendulum;

/*/////////////////////////////////////////////////////////
 TESTS
//////////////////////////////////////////////////////////*/
// [ ] TODO test max length
// [ ] TODO test angle range
// [ ] TODO test consistency of constant params
/*/////////////////////////////////////////////////////////
END TESTS
//////////////////////////////////////////////////////////*/

calc_position(pendulum p) {
	p.pos[0] = 
	p.pos[1] = 

}




