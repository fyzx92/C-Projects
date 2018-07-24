/*
* Authored by Bryce Burgess
*
* functions for circularly linked list
*/


#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} node;






//////////////////////////////////////////////
//////////// create list head ////////////////
void initializeList() {
	node* root;
	root = malloc(sizeof(node*));
	root->next = root;
	root->prev = root;
}






////////////////////////////////////////////////
//////////// get value at index ////////////////
int ListIndexValue(node* root, int idx) {
	node *T;
	T = root;
	if (T != NULL) {
		if (idx >= 0) { /// go through list forwards
			for (int i = 0; T->next != NULL && T->next != root; i++) {
				if (i == idx) return T->data;
				T = T->next;
			}
		}
		if (idx < 0) { /// go through list backwards
			for (int i = 0; T->prev != NULL && T->prev != root; i--) {
				if (i == idx) return T->data;
				T = T->prev;
			}
		}
	
	}
	printf("Error: requested index %d is out of range for list of length %d",idx, i);
	return -1;
}






/////////////////////////////////////////////////
//////////// append to list /////////////////////
void Append(node* root, int newValue) {
	node *T;
	T = root;

	for (int i = 0; T->next != NULL && T->next != root; i++) {
		T = T->next;
	}
	if (T->next == NULL || T->next == root) {
		T->next = malloc(sizeof(node*));
		T->next->prev = T;
		T = T->next;
		if (T == NULL) {
			printf("out of memory");
		}
		T->data = newValue
		T->next = root;
	}
	return;
}






////////////////////////////////////////////////
//////////// insert a node at index ////////////
void InsertNode(int idx, node *root, int insertValue) {
	node *T, *U, insertedNode;
	T = U = root;

	/// find location
	if (idx >= 0) { /// go through list forwards
		for (int i = 0; (T->next != NULL) && (T->next != root); i++) {
			if (i == idx) {
				insertedNode = T;
				T->next = insertedNode;
				break;
			}
			U = T;
			T = T->next;
		}
	}


	if (idx < 0) { /// go through list backwards
		for (int i = 0; (T->prev != NULL) && (T->prev != root); i--) {
			if (i == idx) {
				insertedNode = T;
				T->next = insertedNode;
				break;
			}
			T = U;
			U = U->prev;
		}
	}
	
	/// fix pointers
	insertedNode->next = T;
	T->prev = insertedNode;
	U->next = insertedNode;

	/// put data into new node
	insertedNode->data = insertValue;
	
	
	return;
}





////////////////////////////////////////////////
//////////// delete a single node //////////////
void DeleteNode(node* root, int idx) {
	node *T, *U;
	T = U = root;
	if (idx >= 0) { /// go through list backwards
		for (int c = 0; (T->next != NULL) && (T->next != root); c++) {
			if (c > idx) break;
			U = T;
			T = T->next;
		}
	}

	if (idx < 0) { /// go through list backwards
		for (int c = 0; (T->prev != NULL) && (T->prev != root); c--) {
			if (c < idx) break;
			T = U;
			U = U->prev;
		}
	}
	
	/// fix pointers
	U->next = T->next;
	T->next->prev = U;
	
	free(T);

	return;
}


/////////////////////////////////////////////////
//////////// delete entire list /////////////////
void DeleteList1(node *root) {
	node *T, *U;
	T = U = root;
	while (T->next != NULL && T->next != root) {
		U = T;
		T = T->next;
	}
	while (root != NULL) {
		free(T);
		T = U;
		U = T->prev;
	}
	free(root);
	return;
}

//////////////////////////////////////////////////
//////////// delete entire list //////////////////
void DeleteList2(node *root) {
	node *T;
	while (root != NULL) {
		T = root;
		while (T->next != NULL && T->next != root) {
			T=T->next;
		}
		free(T);
	}
	return;
}





//////////////////////////////////////////////////
//////////// change data at index ////////////////
void EditNode1(node *root, int editN, int newValue) {
	node *T, *U;
	T = U = root;
	if (idx >= 0) { /// go through list backwards
		for (int c = 0; (T->next != NULL) && (T->next != root); c++) {
			if (c > idx) break;
			U = T;
			T = T->next;
		}
	}

	if (idx < 0) { /// go through list backwards
		for (int c = 0; (T->prev != NULL) && (T->prev != root); c--) {
			if (c < idx) break;
			T = U;
			U = U->prev;
		}
	}

	T->data = newValue;
	
	return;
}


//////////////////////////////////////////////////
//////////// change data at index ////////////////
void EditNode2(node *root, int editN) {
	node *T, *U;
	T = U = root;
	if (idx >= 0) { /// go through list backwards
		for (int c = 0; (T->next != NULL) && (T->next != root); c++) {
			if (c > idx) break;
			U = T;
			T = T->next;
		}
	}

	if (idx < 0) { /// go through list backwards
		for (int c = 0; (T->prev != NULL) && (T->prev != root); c--) {
			if (c < idx) break;
			T = U;
			U = U->prev;
		}
	}

	scanf("new value is %d \n",T->next->data);
	return;
}
