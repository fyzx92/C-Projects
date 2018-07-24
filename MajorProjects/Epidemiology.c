/*
* Authored by Bryce Burgess
* Epidemiological Analysis
*
*
*/



typedef struct node {
	int n_people;
	struct node *prev_node;
} node;

node build_node() {
	node *p;
	p = malloc(sizeof(node));
	return *p
}

int infect(node infected) {
	double infect_rate = 0.2;
	int infect_n = infected.n_people*infect_rate;
	return infect_n;
}

int die(node infected) {
	double death_rate = 0.1;
	int n_died = (int)(infected.n_people*death_rate);
	return n_died;
}

node recover(node infected) {
	double recover_rate = 1-death_rate;
	double recover_rate = 0.9;
	int n_recovered = (int)(infected.n_people*recover_rate);
	return n_recovered;
}

int main() {
	
	/// set up different boxes
	node *p_infected;
	p_infected = malloc(sizeof(node));
	infected = *p_infected;

	node *p_uninfected;
	p_uninfected = malloc(sizeof(node));
	uninfected = *p_uninfected;

	node *p_immune;
	p_immune = malloc(sizeof(node));
	immune = *immune;

	node *dead;
	p_dead = malloc(sizeof(node));
	dead = *p_dead;

	/// construct graph
	uninfected.prev_node = NULL;
	infected.prev_node = p_uninfected;
	immune.prev_node = p_infected;
	dead.prev_node = p_infected;

	///


}
