//This program is designed to find the sum of all multiples \
of 3 or 5 that are less than 10000

#include <stdio.h>

int main() {

	int sum = 0;
	int i;

	for (i=1; i<1000; i++) {
		if (i%5==0) { //find all multiples of 5 less than 1000
			sum +=i;  //add those multiples to the total
		}
		else if (i%3==0) {//do the same for 3
			sum +=i;
		}

	}
	printf("%d", sum);
	
return 0;
}
