/*
*Authored by Bryce Burgess
*
*The scanf function
*/

#include <stdio.h>

int main(int argc, char** args) {
	int integer;
	char character;
	char string[10];
	scanf("enter an integer: %d", &integer);
	scanf("enter a character: %c", &character);
	scanf("enter a string fewer than 10 characters: %9s", string);


}
