/*
* Authored by Bryce Burgess
* to find all primes less than some number n
*/

#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x)/sizeof((x)[0]))
typedef enum{false, true} bool;

int * findPrimes(int n, int p[]) {
	int j = 0;
	int c = 2; // candidate primes
	while (c <= n) {
		bool isPrime = true;
		int t = 2; // test number for primeness
		while (t < c) {
			// check if c is divisible by t
			if (c%t == 0) {
				isPrime = false;
				break;
			}
			// increment t
			if (t<3) t++;
			else if (t>=3)t += 2;
		}
		// record prime numbers
		if (isPrime) {
			p[j++] = c;
			printf("%d is a prime less than %d \n", c, n);
		}
		if (c<3) c++;
		else if (c>=3) c += 2;
	}

	return &p[0];
}

int main() {

	int n = 938;
	int numPrimes = 2*n/((int)log(n));
	int p[n/2];
	int i = 0;
	for (i = 0; i<NELEMS(p); i++) p[i] = 0;

	// Unsure about this syntax
	p[0] = *findPrimes(n,p);
	
	// [ ] TODO this won't print, because p is not returned
	printf("The primes less than %d are: \n",n);
	for (i = 0; i<NELEMS(p); i++) {
		if (p[i] > 0) {
			printf("%d \n",p[i]);
		}
	}
}
