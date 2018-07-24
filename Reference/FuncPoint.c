/*
*Authored by Bryce Burgess
*to show how pointers can help pass arrays through functions
*/

#include <stdio.h>
#include <stdlib.h>

#define NELEMS(x) (sizeof(x))/(sizeof(x)[0])

void chArray(int array1[]) {
	for (int i = 0; i<5; i++) {
		array1[i] = 10+i;
	}
}
int *chArray2(int array2) {
	int *pn = array2[0];
	int pnTemp = pn;
	for (int i = 0; i<5; i++) {
		*pnTemp = 20+i;
		pnTemp++;
	}
	return pn;
}

int *chArray3() {
	int arraySize = 5;
	int *array3 = malloc(arraySize);
	if(!array3)
		return NULL;
	for (int i=0; i<arraySize;i++)
		array3[i] = 30+i;
	return array3;

}

void chArray4(int *array4) {
	int arraySize = 5;
	for (int i=0;i<arraySize;i++) {
		array4[i] = 40+i;
	}
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
int main() {
	/// Initial array, no changes
	int array[5] = {1,2,3,4,5};
	for (int i = 0; i<5; i++) {
		printf("array of %d is %d\n", i, array[i]);
	}

	printf("\n");
	/// Change existing array within function	
	chArray(array);
	for (int i = 0; i<5; i++) {
		printf("array of %d is now %d\n", i, array[i]);
	}

	printf("\n");
	/// Assign array from function
	int *array2[5];
	array2[0] = *chArray2();//[ ] TODO get elements of array
	for (int i = 0; i<5; i++) {
		printf("array of %d is now %d\n", i, array2[i]);
	}

	printf("\n");
	/// 
	int *array3 = chArray3();
	if (array3) {
		for (int i = 0; i<5; i++) {
			printf("array of %d is now %d\n", i, array3[i]);
		}
		free(array3);
	}

	printf("\n");
	/// 
	int array4[5] = {0};
	chArray(array4);
	for (int i = 0; i<5; i++) {
		printf("array of %d is now %d\n", i, array4[i]);
	}




}
