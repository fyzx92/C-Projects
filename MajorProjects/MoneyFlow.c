/*
* Authored by Bryce Burgess
*
* model the flow of money between companies and people
*/

#include <stdio.h>
#include <stdlib.h>

#define NELEMS(x) (sizeof(x))/(sizeof((x)[0]))

typedef struct person {
	char name[];
	int wealth;

	// links to company.wokers and company.wages
	char job[];
	int income;

	// links to company.shareholders and company.profitPercents
	char *investments[];
	double investmentPercents[];

	// links to company.products and company.prices
	char *purchases[];
} person;

typedef struct company {
	char name[];
	int profit;

	// links to person.job and person.income
	char *workers[];
	int wages;

	// links to person.investents and person.investmentReturns
	char *investors[];
	double profitPercents[];
	
	// links to person.purchases and person.expenseValues
	int price;
} company;

typedef struct entity {
	person p;
	company c;
} entity;

// Create person object with things that person gets to choose
person * makePerson() {
	person *pp;
	pp = (*person)*malloc(sizeof(person));
	p = *pp;

	p.name = "";
	p.wealth = 100;

	p.job = "";

//	p.investments = ;
//	p.investmentPercents = ;

	return p;
}

// Create company object with things that company gets to choose
person * makeCompany() {
	company *pc;
	pc = (* company)*malloc(sizeof(person));
	company c = *pc;

	c.name = "";

	c.wages = 100*rand();

	c.price = 10*rand();

	return c;
}

entity * updateEntities(person p[], company c[]) {
	int i = 0;
	for (i = 0; i < NELEMS(p); i++) {
		// wealth from income
		p[i].wealth += p[i].income;
		// wealth from investments
		for (j = 0; j < NELEMS(p.investments); j++) {
			for (k = 0; k < NELEMS(c); k++) {
				if (p[i].investments[j] == c[k].name) {
					p[i].wealth += p[i].investmentPercents[j]*c[k].profit;
				}
				// check income
			//	if (c[k].name == p[i].job) {
			//		p[i].income = c[k].wages;
			//	}
			}
		}
		// choice of job
	//	p.job = p.job;// [ ]TODO allow quitting
	}
}

// Update remaining parameters after companies are made
person * updatePerson(person p, company c[]) {
	int i = 0;
	int j = 0;

	// record total wealth
		//working
	p.wealth += p.income;
		//investment
	for (i = 0; i < NELEMS(p.investments[]); i++) {
		for (j = 0; j < NELEMS(c); j++) {
			if (p.investments[i] == c[j].name) {
				p.wealth += p.investmentPercents[j]*c[j].profit;
			}
		}
	}
// alternate formalism for investment return calculation	
//	for (i = 0; i < NELEMS(c[]); i++) {
//		for (j = 0; j < NELEMS(c[i].investors); j++) {
//			if (c[i].investors[j] == p.name) {
//				p.wealth += c.profitPercents[j]*c[i].profit;
//			}
//		}
//	}
		// expenses
	for (i = 0; i < NELEMS(c); i++) {
		for (j = 0; j < NELEMS(p.purchases); i++) {
			if(c[i].name == p.purchases[j]) { // purchases defined just by company name
				wealth -= c[i].price;
			}
		}
	}

	// manage job and working income
	p.job = p.job;// [ ]TODO allow quitting
	for(i = 0; i < NELEMS(c); i++) {
		if (c[i].name == p.job) {
			p.income = c.wages;
		}
	}

	// manage income from investments
	p.investments = p.investments;// [ ]TODO allow investments and percents to change
	p.investmentPercents = p.investmentPercents;

	// manage list and costs of purchases
	p.purchases = p.purchases;// [ ]TODO allow purchases to change

	return p;
}

// Update remaining parameters after people are made
company * updateCompany(company c, person p[]) {
	int i = 0;

	// record profit of the company
		// all money is distributed to investors or workers
	c.profit = 0;
		// income from purchases
	for (i = 0; i < NELEMS(p); i++) {
		for (int j = 0; j < NELEMS(p.purchases); i++) {
			if (c.name == p[i].purchases[j]) { // purchases defined just by company name
				c.profit += c.price;
			}
		}
	}
		// money to workers
	for (i = 0; i < NELEMS(p); i++) {
		if (c.name == p[i].job) { // assume workers choose jobs, not companies choosing workers
			c.profit -= c.wage;
		}
	}

	// manage workers and their wages
	c.wage = c.wage;// [ ]TODO allow promotions 

	// manage investors and distribution of profits
	c.investors = c.investors;
	c.profitPercents = c.profitPercents;// [ ]TODO allow share splitting

	// manage price per unit
	c.price = c.price;// [ ]TODO allow prices to change

	return c;
}

/*
// check that all investments are in agreement
bool checkInvestments(person p[], company c[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	int h = 0;
	int m = 0;
	int n = 0;
	
	bool listsMatch = false;
	bool percentMatch = false;

	// [ ] TODO how to record correctness
	for(i = 0; i < NELEMS(c); i++) {
		for(j = 0; j < NELEMS(p); j++) {
			for(k = 0; k < NELEMS(c[i].investors); k++) {
				for(h = 0; h < NELEMS(p[j].investments); h++) {

					// check investment lists against investor lists
					if (p[j].investments[h] == c[i].name) {
						if (c[i].investors[k] == p[j].name) {
							m++;
						}
					}

					// check if all percents match
					if (p[j].investmentPercents[h] == c[i].profitPercents[k]) {
						n++;
					}
				}
			}
		}
	}

	// [ ] TODO CHECK THAT THESE ARE CORRECT
	if (m == NELEMS(p[j].investments)*NELEMS(c[i].investors)) {
		listsMatch = true;
	}
	if (n == NELEMS(p[j].investmentPercents)*NELEMS(c[i].profitPercents)) {
		percentMatch = true;
	}

	return (listsMatch && percentMatch);
}
*/

int main() {
	int i = 0;
	int j = 0;

	// make number of people to simulate
	int nPeople = 10;
	person people[nPeople];
	for (i = 0; i<nPeople; i++) {
		people[i] = makePerson();
	}
	// make number of companies to simulate
	int nCompanies = 5;
	company companies[nCompanies];
	for (i = 0; i<nCompanies; i++) {
		companies[i] = makeCompany();
	}
	// finish initializing people
	for (i = 0; i<nPeople; i++) {
		people[i] = initializePerson();
	}
	// finish initializing companies
	for (i = 0; i<nCompanies; i++) {
		companies[i] = initializeCompany();
	}

	// make matrix representing people
	int investmentMatrix[NELEMS(p)][NELEMS(c)];
	for(j = 0; j< NELEMS(c); j++) {
		for(i = 0; i < NELEMS(p); i++) {
			// for each company, select random people
			// assign random values to those people (must add to 1)
		}
	}

	int runtime = 1000;
	int t = 0;
	for(t = 0; t<runtime;,t++) {
		// run simulation
		for (i = 0; i<nPeople; i++) {
			updatePerson();
		}
		for (i = 0; i<nCompanies; i++) {
			updateCompany();
		}
