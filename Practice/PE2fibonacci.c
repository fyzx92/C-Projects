//This program finds the sum of all even fibonacci numbers \
less than 4 million

#include <stdio.h>

int main() {
	int fib1 = 1;
	int fib2 = 2;
	int fibOut = 0;//progressing fibonacci number
	int sum = fib2;
	int limit = 4000000;

	while( fibOut < limit ) {
	
		if ( fibOut%2 == 0 && fibOut<limit ) { //add to sum if fibOut is even and \
		                                        less than the limit
			sum += fibOut;
		}

		fibOut=fib1+fib2;//calculate fibonacci sequence
		fib1=fib2;
		fib2=fibOut;

	}
	
	printf("the sum of all even fibonacci's below %d is %d",limit, sum);

return 0;
}
