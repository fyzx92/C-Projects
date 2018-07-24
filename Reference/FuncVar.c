/*
*Authored by Bryce Burgess
*to reference how variable changes persist through function calls
*/

#include <stdio.h>


void changeVar1(int v) {
	v = v+3;
}

int changeVar2(int v) {
	return v = v+5;
}

int main() {

	int var = 15;
	printf("variable is %d \n",var);
	changeVar1(var);
	printf("After void function, variable is now %d \n", var);
	var = changeVar2(var);
	printf("After int function, variable is now %d \n", var);
}
