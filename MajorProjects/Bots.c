/*
* Authored by Bryce Burgess
* construct bots that can perform a task
*/


#include <stdio.h>
#include <stdlib.h>

/// building blocks for bots
typedef struct neuron {
	double sum;
	neuron *out;
	double *weights;
	struct neuron *in;
} neuron;

/// bot that tries to complete task
typedef struct studentBot {
	neuron network[];
	neuron connections[][];
} studentBot;

/// test bot performance
testBot (data, labels) {

}

/// construct new bot
buildBot (int nCells) {
	for (int i=0; i<nCells; i++) {
		neuron *pcell[i];
		pcell[i] = malloc(sizeof(neuron));
		neuron cell[i] = *pcell[i];
	}
	for (int i=0; i<nCells; i++) {
		
	}
	for (int i=0; i<nCells; i++) {
	}
	for (int i=0; i<nCells; i++) {
	}
}

/// create modified copies of bot
mutateBot (studentBot bot) {
	bot->connections = bot->connections;
}

int main() {
	int i = 0;
	/// build some student bots
	/// get data
	/// test those bots
	/// mutate best bots
	/// repeat
}
