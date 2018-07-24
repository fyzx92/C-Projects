/*
* Authored by Bryce Burgess
* Bubble sort - swap adjacent elements to be in correct order
*/

#include <stdio.h>
#define NELEMS(x) sizeof(x)/(sizeof((x)[0]))



int main() {
	int i = 0;

	/// set up list to sort
	int listSize = 12;
	int toSort[listSize];
	for (i=0; i<listSize; i++) toSort[i] = rand();
	int newList[listSize] = toSort;

	/// 
	bool sorted = false;
	int temp = toSort[0];
	int swapCount = 0;
	while(!sorted) {
		swapCount = 0;
		for (i=0; i<NELEMS(toSort)-1; i++) {
			if (toSort[i] > toSort[i+1]) {
				temp = toSort[i];
				toSort[i] = toSort[i+1];
				toSort[i+1] = temp;
				swapCount++;
			}
		}
		if (swapCount == 0) break;
	}
}
