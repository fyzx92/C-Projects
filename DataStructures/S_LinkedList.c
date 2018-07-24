/*
* Authored by Bryce Burgess
* Create a Singly Linked List data structure
*/

#include <stdio.h>
#include <stdlib.h>
//#include "S_LinkedList.h"

typedef struct intNode {
	int data;
	struct intNode *next_node;
} intNode;

int main(int argc, char *args[]) {

	/// Define a first element of LL
	intNode *root;
	root = malloc(sizeof(intNode));
	printf("root has value %d, and the next address is %p \n", root->data, root->next_node);

	/// equivalent to (*root).next: get the structure "next" that root points to
	root->next_node = 0;	
	root->data = 15; 

	/// Traverse list
	intNode *T;
	T = root; /// T is a pointer
	/// Check that the current node is not null
	if (T != 0) {
		/// While the address of the next element is not null,
		while (T->next_node != 0) {	
			/// go to the next element of the list, ends at last element of list
			T = T->next_node;		
		}
	}




	/// Create node at the end of the list
	/// allocate memory for the next element, nodes don't have names
	T->next_node = malloc(sizeof(intNode *)); 
	T = T->next_node; /// is pointer to this node no longer null?
	if (T == NULL) {
		printf("out of memory");
		return 0;
	}
	T->data = 42; 
	T->next_node = 0;
	
	return 0;
}

