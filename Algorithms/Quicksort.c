/*
* Authored by Bryce Burgess
* C implementation of quicksort
*/



#include <stdio.h>
#define NELEMS(x) sizeof(x)/(sizeof(x)[0])

int * sort(list) {

	int middle = NELEMS(list)/2;
	int *newList1;
	int *newList2;

	int j=0;
	int i=0;
	for (i=0; i<NELEMS(list); i++) {
		if (list[i] <= list(middle)) {
			newList1[j++] = list[i];
		}
	}
	j=0;
	for (i=0; i<NELEMS(list); i++) {
		if (list[i] >  list(middle)) {
			newList2[j++] = list[i];
		}
	}

	sort(newList1);
	sort(newList2);
	merge(newList1, newList2)
}

int main() {

// 1. start with orderable list
// 2. select middle element
// 3. put all greater elements above, smaller elements below
// 4. split each half
// 5. start back at step 2

}
