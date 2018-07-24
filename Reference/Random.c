/*
* Authored by Bryce Burgess
* methods for generating random numbers
*/

#include <stdio.h>

// return random number b/w 0 and 1
double random1() {
	return ((double)rand())/RAND_MAX;
}

// return random integer less than some integer bound
int random2(int max) {
	return rand()%max;
}

// return random integer between two integers
int random3(int min, int max) {
	if (max < min) {
		int temp = max;
		max = min;
		min = temp;
	} else if (max == min) return max;
	return rand()%(max-min) + min;
}

// return random as double less than any max
double random4(double max) {
	return (( (double)rand() )/RAND_MAX )%max * RAND_MAX;
}

int main() {
	
	printf("rand() gives an integer: %d", rand());
	printf("random1() gives an integer: %f", random1());
	int max = 200;
	printf("random2(%d) gives an integer: %d", max, random2(max));
	int min = 30;
	max = 200;
	printf("random3(%d, %d) gives an integer: %d", min, max, random3(min, max));
	double dmax = 15.7;
	printf("random4(%f) gives an integer: %f", dmax, random4(dmax));

}
