/*
*
* Authored by Bryce Burgess
*
* Simple discrete time neural network
*
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct neuron {
	/// connections
	double *inputs;
	double *weights;

	double value;
} neuron;

double neuronValue(neuron n) {
	n.value = 1./(1.+exp(-weights*inputs))

}





int main(){}
