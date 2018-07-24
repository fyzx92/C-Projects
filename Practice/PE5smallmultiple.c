/*
* Authored by Bryce Burgess
* Find the smallest number that is evenly divided by every number from 1 to 20
*/
#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))
typedef enum{false, true} bool;

void findPrimes(int n, int p[]) {
	int j = 0;
	int c = 2;
	while (c <= n) {
		bool isPrime = true;
		int t = 2;
		while (t < c) {
			if (c%t == 0) {
				isPrime = false;
				break;
			}
			t++;
		}

		if (isPrime) {
			p[j++] = c;
			printf("%d has been added to prime array \n", c);
		}
		c++;
	}
	return;
}

int main() {
	int n = 20;
	int p2[n];
	int i = 0;
/// find primes < 20
/// take powers of those primes that are also < 20
	for (i = 0; i < NELEMS(p2); i++) p2[i] = 1;

	for (i = 0; i < n; i++) {
		findPrimes(n,p2);
	}

	int powers[NELEMS(p2)];
	for (i = 0; i < NELEMS(p2); i++) powers[i] = 1; 

	int product = 1;
	for (i = 0; i < n; i++) {
		powers[i] = 1;
		if  (p2[i] != 1) {
			powers[i] = (int)(log(20)/log(p2[i]));
		}
		printf("powers[i] = %d, p2[i] = %d \n", powers[i], p2[i]);
		product = product*pow(p2[i],powers[i]);
		printf("the product is currently %d \n", product);
	}
}
