/*
* Authored by Bryce Burgess
* For reference to find prime factors 
*/

#include <stdio.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void factors(int n, int p[], int j) {
	/// if n is divisible by c, store c, and continue with n/c
	int c = 2;
	while (c <= n) {
		if (c > n) {
			printf("error in loop, j is %d \n",j);
			break;
		}
		if (n%c == 0) { 
			printf("%d has been added to p \t", c);
			printf("n has been reduced to %d \t", n/c);
			printf("j is %d \n", j);
			p[j++] = c;
			n=n/c;
			if (n==c) break;
			c=2;
		}
		else c++;
	}
	return;
}

int main() {
	/// set up number to factor, n, and array to hold factors, p.
	int n = 26357;
	int p[n/2];
	int i=0;
	for (i=0; i<NELEMS(p); i++) {
		p[i]=0; 
	}

	int j = 0;
	factors(n, p, j);
	
	
	printf("the prime factors of %d are:\n",n);
	for (i=0; i<NELEMS(p); i++) {
		if (p[i] > 0) {
			printf("%d \n", p[i]);
		}
	}
	
}
