
/*
* Authored by Bryce Burgess
* find the difference between the square of a sum, and the sum of squares
*
*/

#include <stdio.h>

#define NELEMS(x) (sizeof(x)/sizeof((x)[0]))

int main() {
	int n = 100;
	printf("n = %d \n", n);

	int sum1 = (n+1)*n/2;
	int sum2 = 0;
	int i = 0;
	
	for (i = 1; i <= n; i++) {
		sum2 += i*i;
	}

	sum1 = sum1*sum1;
	printf("the sum of squares is %d \n", sum2);
	printf("the square of the sum is %d \n", sum1);
	printf("the difference between the sum of squares and the square of the sum is %d \n",sum1-sum2);
}
