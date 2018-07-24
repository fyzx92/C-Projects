/*
* Authored by Bryce Burgess
* model the flow of money between companies and people
*/

#include <stdio.h>
#include <stdlib.h>

#define NELEMS(x) (sizeof(x))/(sizeof((x)[0]))

typedef struct person {
	//char *name
	int ID;
	char name[20];
	int wealth;

	/// links to company.wokers and company.wages
	//char *job
	int jobID;
	char job[20];
	int income;

	/// links to company.products and company.prices
	int purchases[7];
	//int *purchases;
} person;

typedef struct company {
	//char *name
	int ID;
	char name[20];
	int profit;

	/// links to person.job and person.income
	int wages;

	/// links to person.purchases and person.expenseValues
	int price;
	//int income;
} company;

double random() {
	return ( (double)rand() )/RAND_MAX;
}

/// Create person object with things that person gets to choose
person * makePerson(int pID, int jobID) {
	person *pp;
	pp = malloc(sizeof(person));
	person p = *pp;

	p.ID = pID;
	p.name = ("%d", pID); //[ ] TODO this cannot be assigned (also p.job, c.name)
	p.wealth = 10000;

	p.jobID = jobID;
	p.job = ("%d", jobID);
	//p.income = 0;

	for (int i=0; i<NELEMS(p.purchases); i++) {
		p.purchases[i] = (random()<0.3);
		p.purchases[i] = random()*p.purchases[i];
	}

	return &p;
}

// Create company object with things that company gets to choose
company * makeCompany(int ID) {
	company *pc;
	pc = malloc(sizeof(person));
	company c = *pc;

	c.ID = ID;
	c.name = ("%d", ID);
	c.profit = 0;

	c.wages = 100*random();

	c.price = 10*random();
	//c.income = 0;
	return &c;
}

/// Update remaining parameters after companies are made
person * updatePerson(person p, company c[], double investments[][]) {
	int i = 0;
	int j = 0;

	/// record total wealth
		///working
	p.income = 0;
	p.income += c[p.ID].wages; 
		///investment
	for (j=0; j<NELEMS(c) ;j++) {
		p.income+= investments[p.ID][j]*c.profit; 
	}
		/// expenses
	for (i=0; i<NELEMS(c); i++) {
		for (j=0; j<NELEMS(p.purchases); i++) {
			if(c[i].name == p.purchases[j]) { /// purchases defined just by company name
				p.income -= c[i].price;
			}
		}
	}
	p.wealth += p.income;

	/// manage job and working income
	//p.job = p.job;// [ ]TODO allow quitting
	//for (i=0; i<NELEMS(c); i++) {
	//	if (c[i].name == p.job) {
	//		p.income = c.wages;
	//	}
	//}

	// manage list and costs of purchases
	//p.purchases = p.purchases;// [ ]TODO allow purchases to change

	return &p;
}

/// Update remaining parameters after people are made
company * updateCompany(company c, person p[], double investments[][]) {
	int i = 0;

	/// record profit of the company
		/// all money is distributed to investors or workers
	c.profit = 0;
		/// income from purchases
	for (i=0; i<NELEMS(p[]); i++) {
		for (int j=0; j < NELEMS(p[i].purchases); i++) {
			if (c.name == p[i].purchases[j]) { /// purchases defined just by company name
				c.profit += c.price;
				break;
			}
		}
	}
		/// money to workers
	for (i=0; i<NELEMS(p); i++) {
		if (c.name == p[i].job) { 
			c.profit -= c.wages;
		}
	}
		/// pay investors
	for (i=0; i<NELEMS(c); i++) {
		c.profit -= investments[i][c.ID]*c.profit; 
	}

	/// manage workers and their wages
	//c.wage = c.wage;// [ ]TODO allow promotions 

	/// manage price per unit
	//c.price = c.price;/// [ ]TODO allow prices to change

	return &c;
}

int main() {
	int i = 0;
	int j = 0;

	/// make number of people to simulate
	int nPeople = 10;
	int nCompanies = 5;
	person people[nPeople];
	for (i=0; i<nPeople; i++) {
		people[i] = *makePerson(i);
	}

	/// make number of companies to simulate
	company companies[nCompanies];
	for (i=0; i<nCompanies; i++) {
		companies[i] = *makeCompany(i);
	}

	/// create investment matrix
	double investments[nPeople][nCompanies];
	double normalize;
	for (j=0; j<nCompanies; j++) {
		for (i=0; i<nPeople; i++){
		normalize = 0;
			/// choose investment frequency
			investments[i][j] = (random()>0.3);
			investments[i][j] = investments[i][j]*random();
			normalize += investments[i][j];
		}
		for (i=0; i<nPeople; i++) {
			investments[i][j] /= normalize;
		}
	}

///////////////////// DONE INITIALIZING ////////////////
	printf("initialization finished");

	int runtime = 1000;
	int t = 0;
	for (t=0; t<runtime; t++) {
		// run simulation
		for (i=0; i<nPeople; i++) {
			people[i] = updatePerson(people[i], companies, investments);
		}
		for (i=0; i<nCompanies; i++) {
			companies[i] = updateCompany(companies[i], people, investments);
		}
	}
}
