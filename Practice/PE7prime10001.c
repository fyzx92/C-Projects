#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

typedef enum{false, true} bool;

bool isPrime(long p) {
	bool isP = true;
	for (int i = 2; i <= ceil(sqrt(p)); i++) {//slow method, find way to divide only by smaller primes
		//printf("checking %ld for primality\n", p);
		if (p%i==0) {
			isP = false;
			break;
		}
	}
	return isP;
}

int main() {

	int n = 10001;
	int c = 2;
	long lastPrime;
	long p = 3;
	printf("variables initialized \n");

	while (c <= n) {
		if (isPrime(p)) {
			lastPrime = p;
			printf("the %dth prime is %ld \n", c, lastPrime);
			c++;
		}
		p++;
	}
	printf("prime number %d is %ld \n", n, lastPrime);
}
