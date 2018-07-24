/*
* Authored by Bryce Burgess
*
* functions for circularly linked list
*/





typedef struct node {
	int data;
	struct node *next;
} node;


///////////////////////////////////////
//////////// create list head /////////
void initializeList() {
	node* root;
	root = malloc(sizeof(node*));
	root->next = 0;
}


/////////////////////////////////////////
//////////// get value at index /////////
int ListIndexValue(node* root, int idx) {
	node *T;
	T = root;
	if (T != NULL) {
		for (int i = 0; T->next != NULL && T->next != root; i++) {
			if (i == idx) return T->data;
			T = T->next
		}
	
	}
	printf("Error: requested index %d is out of range for list of length %d",idx, i);
	return -1;
}


void Append(node* root) {
	node *T;
	T = root;

	for (int i = 0; T->next != NULL; i++) {
		T = T->next
	}
	if (T->next == NULL || T->next == root) {
		T->next = malloc(sizeof(node*));
		T=T->next;
		if (T == NULL) {
			printf("out of memory");
		}
		T->next = root;
	}

}


void InsertNode(int idx, node *root, int insertValue) {
	node *T, *U, insertedNode;
	T=U=root;

	for (int c = 0; T->next != NULL && T->next != root; c++) {
		if (c == idx-1) break;
		T = T->next;
	}
	
	insertedNode = T;
	T->next = insertedNode;

	insertedNode->data = insertValue;
	return;
}





void DeleteNode(node* root, int idx) {
	node *T, *U;
	T = U = root;
	for (int c = 0; T->next != NULL && T->next != root) {
		if (c > idx) break;
		U = T;
		T = T->next;
	}
	
	U->next = T->next;
	
	free(T);
}


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





void EditNode1(node *root, int editN, int newValue) {
	node *T;
	T = root;
	for (int c=0; T->next != NULL && T->next != root; c++) {
		if (c>editN) break;
		T = T->next;
	}
	T->data = newValue;
	return;
}
void EditNode2(node *root, int editN) {
	node *T;
	T = root;
	for (int c=0; T->next != NULL && T->next != root; c++) {
		if (c>editN) break;
		T = T->next;
	}

	scanf("new value is %d \n",T->next->data);
	return;
}
