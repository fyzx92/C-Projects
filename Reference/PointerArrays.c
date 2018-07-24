/*
* Authored by Bryce Burgess
* Using pointers in arrays
*/

#include <stdio.h>

#define NELEMS(x) sizeof(x)/(sizeof(x)[0])



int main() {
	int i=0, j=0;

	int arr[10];
	int *p = NULL;
	p=&arr[0];

	printf("array values by indexing\n");
	for (i = 0; i<NELEMS(arr); i++) {
		arr[i] = i*6;
		printf("index: %d \t value: %d \n", i, arr[i]);
	}

	printf("array values by pointers\n");
	for (i = 0; i<NELEMS(arr)+3; i++) {
		printf("address: %p \t index: %d \t value: %d \n",(void *)p, i, *p);
		p++;
	}

	int var = 12;
	int *p1 = var;
	int *p2 = &var;
	int p3 = &var;

	int a = *p2;
	int b = **p2;
	int c = ***p2;
	printf("*p1: %p \t p2: %p \t*p2: %p \t**pp2: %p\n", (void *)*p1, (void *)p2, (void *)*p2);

	printf("*pp2 == &p1 %d\n",&p1 == *p2 ); //FALSE
	printf("p1 == &var %d\n",  *p1 == &var);
	printf("**pp2 == var %d\n", a == var); 
	printf("***pp2 == var %d\n", b == var); 

	int size = 10;
	for (i=0; i<size; i++) {
		for (j=0; j<i; j++) {
			
		}
	}
}
