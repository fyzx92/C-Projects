/*
* Authored by Bryce Burgess
* simulate n m sided dice
*
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int NdM(int n, int m){
	int sum = 0;
	for (int i = 0; i<n; i++) {
		sum += n*(int)ceil(rand());
	}
	return sum;
}

int main() {
	bool takingInput = true;
	int sum = 0;
	/// continually takes input
	while (takingInput) {
		
		printf("enter a command:\n 
				NdM - roll N dM and sum the results \n 
				clear - new dice roll \n 
				end - end program");

		scanf("%s", &input);

		/// end the program, stop taking any inputs
		if (input == "end") {
			takingInput = false;
		
		/// clear the current sum to do a new role
		} else if (input == "clear") {
			sum = 0;
		
		/// add static modifier to current sum
		} else if (isdigit(input)) {
			/// [ ] TODO extract modifier value
			modifierSTR = input;
			sum += modifier;
		
		/// add a (series of) rolls to current sum
		} else if(input == /*[ ] TODO no idea how to implement this*/) {

			/// extract n and m from string
			int splitIndex = NULL;
			for (int i = 0; i<NELEMS(input); i++) {
				if (input[i] == "d" && splitIndex == NULL) {
					splitIndex = i;
					i = 0;
				
				/// all characters must be digits, except for one split character
				} else if (!isdigit(input[i]) && splitIndex != NULL) {
					printf("invalid input: try again");
					break;

				} else if (!isdigit(input[i]) && input[i] != "d") {
					printf("invalid input: try again");
					break;
				
				/// extract n and m (as char)
				} else if (i<splitIndex && splitIndex != NULL){
					char Nstr[i] = input[i];
				
				} else if (i>splitIndex && splitIndex != NULL){
					char Mstr[i] = input[i];
				}
			}
			
			sum += NdM(n,m);
		}
	}
}
