/*
* Authored by Bryce Burgess
* simulate n m sided dice
*
*/

#include <stdio.h>
#include <math.h>

int NdM(int n, int m){
	int sum = 0;
	for (int i = 0; i<n; i++) {
		sum += n*(int)ceil(rand());
	}
	return sum;
}

int NdM(int n, int m, int sum){
	for (int i = 0; i<n; i++) {
		sum += n*(int)ceil(rand());
	}
	return sum;
}

int main(int argc, char *args[]) {
	int i = 0;
	int nUniqueDie = argc-1;
	char roll[15][nUniqueDie];
	if (nUniqueDie >= 1) {
		for(i=0; i<nUniqueDie; i++) {
			/// assign n and m into roll
			/// extract n and m into numbers
			/// call die sum
		}
	}

}
