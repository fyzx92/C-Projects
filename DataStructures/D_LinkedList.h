/*
* Authored by Bryce Burgess
*
* Header file for using doubly linked list 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct dNode {
	int data;
	struct dNode *next;
	struct dNode *prev;
} dNode;






//////////////////////////////////////////////////////
/////////////// initialize linked list ///////////////
void InitializeDLL() {
	dNode *root;
	root = (dNode *)malloc(sizeof(dNode *));

	root->next = 0;
}






//////////////////////////////////////////////////////
/////////////// get value at index ///////////////////
int ListIndexData(dNode *root, int idx) {
	dNode *T;
	T = root;
	
	if (T != NULL) {
		for (int i = 0; T->next !=NULL; i++) {
			if (i ==idx) return T->data;
			T = T->next;
		}
	}

	printf("Error: requested index %d is out of bounds for list of length %d", idx, i)
	return -1; /// [ ]TODO need more robust error return
}






//////////////////////////////////////////////////////
/////////////// append node to list //////////////////
void AppendNode(dNode *root) {
	dNode *T;
	T = root;
	while (T->next != NULL) {
		T = T->next;
	}
	T->next = malloc(sizeof(dNode *));
	T->next->next = NULL;
	T->next->prev = &T;
	return;
}






//////////////////////////////////////////////////////
/////////////// insert node //////////////////////////
void InsertNode(int idx, dNode *root, int insertValue) {
	/// find place to insert
	dNode *T, *U, *insertedNode;
	T = U = root;
	
	for(int c = 0; T->next != 0; c++) {
		if (c == idx) break; 
		T = T->next;
	}

	/// copy node to insert after
	insertedNode = T;

	/// connect pointers
	T->prev->next = insertedNode;
	T->prev = insertedNode;
	insertedNode->next = T;

	/// change data value
	insertedNode->data = insertValue;

	return;
}







////////////////////////////////////////////////
///////////////// delete single node ///////////
void DeleteNode(dNode *root, int deleteN) {
	/// Find node to delete
	dNode *T;
	T = root;
	for (int c = 0;T->next != 0, c++) {
		if (c > deleteN) break;
		T = T->next;
	}

	/// fix adjacent pointers
	T->prev->next = T->next;
	T->next->prev = T->prev;

	/// free memory
	free(T);

	return;
}







///////////////////////////////////////////////
////////// delete entire list ////////////////
void deleteList1(dNode *root) {
	dNode *T, *u;
	T = U = root;
	while (T->next != 0) {
		U = T;
		T = T->next;
	}
	while (root != 0) {
		free(T);
		T = U;
		U = T->prev;
	}
	return;
}

void deleteList2(dNode *root) {
	dNode *T;
	while (root != 0) {
		T = root;
		while (T->next != 0) {
			T = T->next;
		}
		free(T);
	}
	free(root);
	return;
}

//////////////////////////////////////////////////
////////// edit node data ////////////////////////
void editNode1(dNode *root, int editN, int newValue) {
	dNode *T;
	T = root;
	
	for (int c = 0; T->next != 0; c++) {
		if (c>editN) break;
		T = T->next;
	}
	T->data = newValue;
	return;
}
void editNode2(dNode *root, int editN) {
	dNode *T;
	T = root;
	
	for (int c = 0; T->next != 0; c++) {
		if (c>editN) break;
		T = T->next;
	}
	scanf("new value is %d \n", T->next->data);
	return;
}

void searchList(dNode *root) {
}
