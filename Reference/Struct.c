/*
* Authored by Bryce Burgess
*
* Struct Basics and syntax
*/
#include <stdio.h>
#include <stdlib.h>

struct Struct1 { /// Declares Struct1 in struct namespace, but is not yet a type.
	int a;
	char *b;
};

typedef struct Struct2 { /// Declares Struct2 in struct namespace, declares as type with typedef and StructType2. Struct and type name can be the same
	int a;
	char *b;

} StructType2;

int main() {

	///Variable Declaration
	struct Struct1 *A; /// "struct" keyword required, since Struct1 is not yet a type
	A = malloc(sizeof(struct Struct1*));
	A->a = 3;
	A->b = "Fred";		/// change value at a pointer

	typedef struct Struct1 StructType1; /// Now StructType1 is a type

	StructType2 *B; /// "struct" keyword not required
	B = malloc(sizeof(StructType2 *));
	B->a = 4;
	B->b = "George";

}
