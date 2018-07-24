/*
*Authored by Bryce Burgess
*
*Functions for a linked list in C
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct intNode {
	void* pdata;
	struct intNode *next;
} intNode;







/////////////////////////////////////////////////////////
////////////////// Initialize ///////////////////////////
void InitializeList() {
	///Define a first element of LL
	intNode *root;
	root = (intNode *) malloc( sizeof(intNode*) );
	printf("root has value %d, and the next address is %d \n", root->data, root->next);


	root->next = 0;	/// This is equivalent to (*root).next: get the member "next" that structure root points to
}







/////////////////////////////////////////////////////////
////////////////// Traverse /////////////////////////////
void TraverseList(intNode *root) { ///TODO figure out needed arguments
	///Traverse list
	intNode *T;
	T = root;

	if (T != 0) {				/// Check that the current node is not null
		while (T->next != 0) {	/// While the address of the next element is not null,
			T = T->next;		/// go to the next element of the list, ends at last element of list
		}
	}
	return;
}







/////////////////////////////////////////////////////////
////////////////// Get Value ////////////////////////////
int ListIndexData(intNode *root, int idx) { ///TODO figure out needed arguments
	///Traverse list
	intNode *T;
	T = root;

	if (T != NULL) {				/// Check that the current node is not null
		for (int i = 0;T->next !=NULL; i++) {/// While the address of the next element is not null,
			if (i == idx) return T->data;/// go to the next element of the list, ends at last element of list
			T=T->next;
		}
	}

	printf("Error: requested index %d is out of bounds for list of length %d", idx, i)
	return -1;/// [ ] TODO need more robust error condition
}






//////////////////////////////////////////////////////////
////////////////// Insert ////////////////////////////////
void append(intNode *root) { ///TODO figure out needed arguments
	intNode *T;
	T = root;
	if (T != 0) {
		while (T->next != 0) { ///Move to end of list
			T = T->next; /// is pointer to this node no longer null?
		}
	}
	T->next = malloc(sizeof(intNode*)); ///allocate memory for the next element, nodes don't have names
	T->next->next = 0;
	
	return;
}






void insertAfterNode(struct intNode *root, int insertAfter, int insertValue) {
	/// find place to insert
	intNode *T;
	T = root;
	if (T != 0) {
		for (int i = 0; T->next != 0, i++) {
			if (i>insertAfter) break;	///stops at node to insert after
			T = T->next; 
		}
	}

	///copy node to insert after 
	intNode *insertedNode;
	insertedNode = T; 

	/// connect previous pointer to inserted entry
	T->next = insertedNode; ///TODO is this right?
	
	/// change data value
	insertedNode->data = insertValue; 
	
	return;
}






////////////////////////////////////////////////////////////
//////////////////// Delete Node ///////////////////////////
void deleteNode(intNode *root, int deleteN) {
	/// find node to delete
	intNode *T;
	T = root;
	if (T != 0) {
		int i = 0;
		while (T->next != 0) {
			if (i<deleteN-1) {
				T = T->next; ///stops before node to be deleted
				i++;
			}
		}
	}
	intNode *U;
	U = T;
	U = U->next;

	/// skip over node to be deleted 
	T->next = U->next;

	/// free memory
	free(&U);

}

//////////////////////////////////////////////////////////////
/////////////////// DELETE LIST //////////////////////////////
void deleteList(intNode *root) {
	intNode *T;
	while (root->next != 0) {
		T = root;
		while (T->next->next != 0) {
			T=T->next;
		}
		free(T->next);
	}
}

/////////////////////////////////////////////////////////////
///////////////////// Sort //////////////////////////////////
void sortNodesAscending(intNode *root) {
	/// Assume same data type (to start)
	/// find node with smallest data point
	/// record pointer address, record next pointer
	///

}

/////////////////////////////////////////////////////////////
//////////////////// Edit //////////////////////////////////
void editNode(intNode *root, int editN, int newValue) {
	/// Find node to change
	intNode *T;
	T = root;
	for (int i = 0; i<=editN; i++) {
		if(T->next == 0) break;
		T = T->next;
	}

	/// edit data value(s)
	T->data = newValue;
}

//////////////////////////////////////////////////////////////
/////////////////////// Merge ///////////////////////////////
void mergeLists(intNode *root1, intNode *root2) {
	/// Check data types of nodes
	/// Append leading node of L2 to end of L1?
	/// get pointer to first data node
	/// find last node of L1
	/// change pointer at end of L1 to start of L2
}

////////////////////////////////////////////////////////////
////////////////////////// Search //////////////////////////
int searchList(intNode *root, int searchVal) {
	intNode *T;
	T= root;
	int counter = 0;
	while (T->next != 0) {
		T = T->next;
		if (T->data == searchVal) counter++;
	}
	return counter; /// return number of instances of search term in list
}
