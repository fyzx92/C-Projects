/*
* Authored by Bryce Burgess
* a doubly linked list
*/

#include <stdio.h>
#include <stdlib.h>
//#include <D_LinkdeList.h>

typedef struct dNode {
	int data;
	struct dNode *next;
	struct dNode *prev;
} dNode;


int main() {

	/// Make the head of the list
	dNode *root;
	root = malloc(sizeof(dNode *));
	root->next = 0;

	/// Traverse list
	dNode *T, *U;
	T = U = root;
	/// T describes pointers forward
	if (T != NULL) {
		while (T->next != NULL) {
			T = T->next;
		}
	}
	/// U describes pointers backwards
	if (U != 0) {
		while (U->next->next != 0) {
			U = U->next;
		}
	}

	/// Append to list
	if (T->next == 0) {
		T->next = malloc(sizeof(dNode *));
		T = T->next;
		if (T==0) {
			printf("out of memory");
			return 0;
		}
		T->next = 0;
		T->prev = U;
	}

}
