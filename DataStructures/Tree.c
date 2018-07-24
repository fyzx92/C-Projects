/*
* Authored by Bryce Burgess
*
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	typedef struct node *left;
	typedef struct node *right;
	typedef struct node *up;
	int value;
} node;

typedef struct tree {
	node root;
} tree;


void TraverseBreadth(node root) {
	
	node *T;
	node *U;
	T = root;
	U = root;
	
	while (/*TODO determine when finished*/) {
		T = U->left;
		T = U->right;
		if (/*something is found*/) {
			U = U->T
		}
	}
};


void TraverseDepth(node root) {
	node *T, *U;
	T = U = root;
	while (/*TODO determine when finished*/) {
		while(T->left !=0) {
			T=T->left
		}
		U=T->up
		T=U->right
	}
};

tree addNodeLeft(tree t) {
	// traverse to desired leaf
	// add node
}

tree addNodeRight(tree t) {
	// traverse to desired leaf
	// add node
}

int main (int argc, char[] *args) {

	// Build tree
	node root;
	root->left  = malloc(sizeof(node));
	root->right = malloc(sizeof(node));
	node *T;
	node *U;

	T = U = root;
	T=T->left 
	T->up = U
	U=U->left 
	T->left = malloc(sizeof(node));

	T=T->right 
	T->up = U
	U=U->right 
	T->right = malloc(sizeof(node));

}
