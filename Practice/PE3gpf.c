#include <stdio.h>

int rPrimeFactors(long n, long greatestPrime) { 
    int c = 2;
    for (c = 2; c <= n; c++) {
		if (c == n) return greatestPrime = c;
        if ((n%c == 0) && (n != c)) {
            return primeFactors(n/c, greatestPrime);
        }
    }
}

int main() {
	
	long n = 600851475143;
	printf("now factoring %ld \n", n);
	int greatestPrime = 2;
	greatestPrime = rPrimeFactors(n, greatestPrime);
	printf("the greatest prime factor of %ld is %d", n, greatestPrime); 
}
                                                                                                                                                                                                                                                
