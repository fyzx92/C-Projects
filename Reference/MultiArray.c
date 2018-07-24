/*
*Authored by Bryce Burgess
*shows how to create and reference elements of a multidimensional array
*/

#include <stdio.h>

typedef struct array2d {
	int arrayDim = 2;
	int arraySize1;
	int arraySize2;
	int array2d(int arraySize1, int arraySize2) {
		int a[arraySize1][arraySize2];
	}
	double array2d(int arraySize1, int arraySize2) {
		double a[arraySize1][arraySize2];
	}
} array2d;

int main() {

	int arrayDim1 = 3;
	int arrayDim2 = 5;
	int multiarray[arrayDim1][arrayDim2];

	/// Assign and print full array
	for(int i=0; i<arrayDim1; i++) {
		for(int j=0; j<arrayDim2; j++) {
			multiarray[i][j] = i*i-j;
			printf("%d \t", multiarray[i][j]);
		}
		printf("\n");
	}

	/// Read one row
	int readRow = arrayDim1-1;
	for(int j=0; j<arrayDim2; j++) {
		printf("%d \t", multiarray[readRow][j]);
	}

	/// Read one column
	int readCol = arrayDim2-2;
	for(int i=0; i<arrayDim1; i++) {
		printf("%d \t", multiarray[i][readCol]);
	}
	
	/// Transpose
	for(int i=0; i<arrayDim1; i++) {
		for(int j=0; j<arrayDim2; j++) {
			multiarray[i][j] = multiarray[j][i];
		}
	}

	/// Use in function
	
}
