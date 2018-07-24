/*
*Authored by Bryce Burgess
*to show how pointer referencing and dereferencing works
*
*/
#include <stdio.h>

int main() {
	
	int n = 5;
	int *pn = &n;
	printf("     n is equal to %d\n", n);
	printf("    pn is equal to %p\n", pn);
	printf("    &n is equal to %p\n", &n);
	printf("   *pn is equal to %d\n", *pn);
	printf("   &pn is equal to %d\n", &pn);
	printf(" *(&n) is equal to %d\n", *(&n));
	printf("&(*pn) is equal to %p\n", &(*pn));
	printf("	*n is invalid syntax");
}
