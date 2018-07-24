/*
*I need to find a way to make this faster
*/
#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))
typedef enum {false, true} bool;

/// use mod function
bool isPalindrome(int r) {
	bool pal = true;
	int rDigits[6];
	int i = 0	
	/// extract digits from r
	for (i = 0; i < NELEMS(rDigits); i++) { 
		rDigits[i] = (r%(int)pow(10,i+1)-r%(int)pow(10,i))/(int)pow(10,i); /// rDigits of 0 is the largest power
	//	printf("%d \n", (r%(int)pow(10,i+1)-r%(int)pow(10,i))/(int)pow(10,i));
		printf("rDigits[%d] equals %d \n", i, rDigits[i]);
	}
	/// check for palindrome
	for (i = 0; i < NELEMS(rDigits); i++) {
		if (rDigits[i] != rDigits[NELEMS(rDigits)-i-1]) { /// -1 to account for 0 indexing
			pal = false;
			break;
		}
	}
	return pal;
}

int main() {

	int factor1;
	int factor2;
	int result;
	bool isPal = false;
	int largestPal = 100001;

	for (int factor1 = 999; factor1 > 99; factor1--) {
		for (int factor2 = 999; factor2 >= factor1; factor2--) {
			result = factor1*factor2;
			printf("the product is %d, with factors %d and %d \n", result, factor1, factor2);
			isPal = isPalindrome(result);
			if (result > largestPal) {
				if (isPal) {
					largestPal = result;
				}
			}
		}
	}
	printf("The largest palindrome is %d \n", largestPal);
}
