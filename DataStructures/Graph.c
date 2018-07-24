/*
* Authored by Bryce Burgess
* undirected unweighted graph
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i;
int j;
int graphSize = 12;



typedef struct node {
///connections
	int data;
	int index;
	char *label;
	struct node * connections;
} node;


/// Adjacency Matrix 
typedef struct adjacencyMatrix {
	int adjMatrix[graphSize][graphSize];
	int labels[graphSize];
	double saturation;
} adjacencyMatrix;


void initialize_AM_sym_unw (adjacencyMatrix am) {
	am.saturation = 0.2;
	for (i=0; i<graphSize; i++) {
		am.labels = i;
		for (j=0; j<i; j++) {
			am.adjMatrix[i][j] = 0;
			if ((double)rand()/RAND_MAX > am.saturation) {
				am.adjMatrix[i][j] = 1;
			}
		}
	}

	/// Make graph symmetric and unweighted
	for (i=0; i<graphSize; i++) {
		for (j=0; j<i; j++) {
			am.adjMatrix[i][j] += am.adjMatrix[j][i];
			am.adjMatrix[i][j] = !!am.adjMatrix[i][j];
		}
	}
	return;
}

int main (int argc, char *args[]) {
	int i = 0, j = 0;

	/// create adjacency matrix
	adjacencyMatrix *am;
	am = malloc(sizeof(adjacencyMatrix));
	initialize_AM_sym_unw(am);
	
	/// Put together node objects into graph according to matrix
	node *graph[graphSize];
	graph = malloc(sizeof(node*graphSize));
	for (i=0; i<graphSize; i++) {
		graph[i]->index = i;
		graph[i]->label = labels[i];
		for (j=0; j<graphSize; j++) {
			if (adjMatrix[i][j] > 0) {
				graph[i]->connections++ = &graph[j]; ///unsure about this
			}
		}
	}
	

	free(graph);
	free(adjacencyMatrix);

}
