/*
* Authored by Bryce Burgess
* Simple neuron, discrete time
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NELEMS(x) sizeof(x)/(sizeof((x)[0]));

const int n_coordinates = 2;
const int set_size = 10;
const int n_classes = 2;
int i = 0, j = 0;

// structure to manage data easily
typedef struct point {
	double coordinates[n_coordinates]; /// one coordinate is the bias
	int label;
} point;



typedef struct data_set {
	point pt[set_size]; /// need to set size
} data_set;




void initialize_dataset(data_set ds) {
	/// set data point coordinates
	int range = 1000;
	for (i = 0; i<NELEMS(ds.pt); i++) {
		for (j = 0; j<NELEMS(ds.pt.coordinates); j++) {
			ds.pt[i].coordinates[j] = rand()%range;

		}
	}

	/// define labels
	int labels[n_classes]; 
	for (i=0; i<NELEMS(labels); i++) labels[i] = i;

	/// label points
	for (i = 0; i<NELEMS(ds); i++) {
		ds.pt[i].label = class_n(ds.pt[i], int labels);
	}

	return;
}


/// still only works for 2 labels
point class_n(point p, int labels[]) {
	/// define coeffs
	double coeffs[NELEMS(p.coordinates) - 1];
	for (i = 0; i < NELEMS(p.coordinates) - 1; i++) {
		coeffs[i] = i+1; /// change this for different planar functions
		//coeffs[i] = rand()/RAND_MAX - RAND_MAX/2;
	}

	double fn_val = 0;
	/// compare output value to input coeffs
	for (i = 0; i<NELEMS(p.coordinates); i++) {
		if (i == NELEMS(p.coordinates) - 1) {
			if (p.coordinates[NELEMS(p.coordinates) - 1] <= fn_val) return labels[0];
			else return labels[1];
		}
		/// compute value of function to compare to
		fn_val += coeff[i] * p.coordinates[i];
	}
}




/// neuron object
typedef struct neuron {
	double inputs[n_coordinates +1];
	double weights[NELEMS(inputs)];
///	double *inputs;
///	double *weights;
	double activation;
	int guess;
} neuron;





/// initialize neuron weights
void initialize_weights(neuron n) {
	for (i = 0; i<NELEMS(n); i++) {
		n.weights[i] = (double)rand()/RAND_MAX;
	}
	return; 
}


/// define sigmoid function
double sigmoid(double x) {
	return double s = 1.0/(1+exp(-x));
}


/// update neuron activation
void compute_activation(neuron n) {
	n.activation = 0;
	double sum = 0;
	for (i=0; i<NELEMS(n.inputs); i++) {
		sum += n.inputs[i] * n.weights[i];
		n.activation += sigmoid(sum);
		n.guess = (n.activation > 0.5);
	}
	return;
}



/// train the perceptron
void train(neuron n, int expected_output) {
	double error = pow(expected_output-n.activation,3);
	//double error = expected_output-n.activation;
	double learn_rate = 0.1;
	for (i=0; i<NELEMS(n.weights); i++) {
		n.weights[i] += error * n.inputs[i] * learn_rate;
	}
	return;
}



int main() {
	data_set *p_ds;
	p_ds = malloc(sizeof(data_set));
	*p_ds = initialize_dataset(*p_ds);

	neuron * pn;
	pn = malloc(sizeof(neuron));
	initialize_weights(*pn);
	
	for (i = 0; i<NELEMS(n.inputs); i++) {
		*pn.inputs[i] = *p_ds.pt[i];
	}
	
	for (i=0; i<NELEMS(*p_ds.pt); i++) {
		compute_activation(*pn);
		train(*pn, *p_ds.pt[i].label);
	}
}
