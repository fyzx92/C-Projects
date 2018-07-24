/*
* Authored by Bryce Burgess
* a circularly linked list
*/

#include <stdio.h>
#include <stdlib.h>
//#include <C_LinkdeList.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} node;


int main() {

	/// Make the head of the list
	node *root;
	root = malloc(sizeof(node *));
	root->next = NULL;
	root->prev = NULL;

	/// Traverse list
	node *T; /// T describes pointers forward
	T = root;
	if (T != NULL) {
		while (T->next != NULL) {
			T = T->next;
		}
	}

	/// Append to list
	int list_length = 1;
	if (T->next == NULL || T->next == root) {
		T->next = malloc(sizeof(node *));
		T = T->next;
		if (T == NULL) {
			printf("out of memory");
			/// return 0;
		}
		T->next = root;
	}

}
