#include <stdio.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int arraySize(int a[]) {
	int s= (sizeof(a))/(sizeof(a[0]));
	return s;
}

int main() {

	int a[10] = {1,2,3,4,5,6,7,8,9,0};

	printf("sizeof(*a) is %ld \n", sizeof(*a));
	printf("sizeof(a) is %ld \n", sizeof(a));
	//printf("sizeof(*a[0]) is %ld \n", sizeof(*a[0]));
	printf("sizeof(a[0]) is %ld \n", sizeof(a[0]));
	printf("the size of a[] from arraySize is %d \n", arraySize(a));
	printf("(sizeof(a))/(sizeof((a)[0])) is %ld \n", sizeof(a)/(sizeof((a)[0])));
	printf("NELEMS(a) is equal to %ld \n", NELEMS(a));
}

