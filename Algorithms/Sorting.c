/*
* Authored by Bryce Burgess
* simple sorting algorithms
*/

#include <stdio.h>

#define NELEMS(x) sizeof(x)/(sizeof( (x)[0] ) )

typedef enum{false, true} bool;

int i = 0;
int j = 0;

int toSort[] = {38, 2, 74, 8, 278, 49, 63, 9, 12, 748, 91, 6, 4, 9, 1285, 9, 61, 9, 3, 8};
int sorted[NELEMS(toSort)];

void print_list(int list) {
	for (i = 0; i < NELEMS(list); i++) {
		printf("%d ", list[i]);
	}
}

// find (next) minimal value and fill new array
void selection_sort() {
	printf("there are %lu elements to sort\n", NELEMS(toSort));
	
	/// take first unsorted element as reference
	int t = toSort[0];

	/// step through sorted elements
	for (i=0; i < NELEMS(sorted); i++) {

		/// step through unsorted elements
		for (j=0; j < NELEMS(toSort); j++) {

			/// (currently) finds minimum value
			if (t > toSort[j]) t = toSort[j]; // just repeats minimum value
		}

		/// add found value to the sorted list
		sorted[i] = t;
	}
	print_list(sorted);
}



// if two adjacent elemtnts are in the wrong order, swap them
void bubble_sort() {
	printf("there are %lu elements to sort\n", NELEMS(toSort));
	int temp;
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (i = 1; i < NELEMS(toSort); i++) {
			if (toSort[i] < toSort[i-1]) {
				temp = toSort[i];
				toSort[i] = toSort[i-1];
				toSort[i-1] = temp;
				isSorted = false;
			}
		}
	}
	print_list(sorted);
	return;
}

/// compare and swap elements at changing distances
void shell_sort() {
	printf("there are %lu elements to sort\n", NELEMS(toSort));
	int temp;
	bool isSorted = false;
	int comparison_dist = NELEMS(toSort)/2;
	while (!isSorted) {
		isSorted = true;
		for (i = comparison_dist; i < NELEMS(toSort); i++) {
			if (toSort[i] < toSort[i-comparison_dist]) {
				temp = toSort[i];
				toSort[i] = toSort[i-comparison_dist];
				toSort[i-comparison_dist] = temp;
				isSorted = false;
			}
		}
		comparison_dist /= 2; // decrease logarithmically? const subtraction?
	}
	print_list(sorted);
	return;
}


/// break into sublists of length 1, compare first elements of sublists
/// [ ] TODO I have no clue how this is working
void merge(int low, int mid, int high) {
	int l1, l2;

	/// split list into two halves, keep stepping variable within those halves
	for (l1 = low, l2 = mid, i=low; l1 <=mid && l2 <= high; i++) {

		/// compare first element in first half and second half
		if (toSort[l1] < toSort[l2]) {

			/// add smaller element to sorted, step along first list
			sorted[i] = toSort[l1++];
		}

		else {

			/// add smaller element to sorted, step along second list
			sorted[i] = toSort[l2++];
		}
	}

	while(l1 <= mid) {
		sorted[i++] = toSort[l1++]
	}
	while(l2 <= high) {
		sorted[i++] = toSort[l2++]
	}
	for (i=low; i<=high; i++) {
		toSort[i] = sorted[i]
	}

}
/// first and last indices
int low = 0;
int high = NELEMS(toSort);
void sort() {
	printf("there are %lu elements to sort\n", NELEMS(toSort));
	int mid;
	/// note: strictly less than, == would probably be infinite
	if (low < high) {
		/// records middle index
		mid = (low+high)/2;

		/// sort first half
		sort(low, mid);

		/// sort second half
		sort(mid+1, high);

		/// merge
		merging(low, mid, high);

	} else return;
}

/// choose middle element, move all greater elements to one side, lesser to the other
void quick_sort() {
	int middle = NELEMS(toSort)/2;
	int *newList1;
	int *newList2;

	int i=0,j=0;
	for (i=0; i<NELEMS(toSort); i++) {
		if (toSort[i] >= toSort[middle]) {
			newlist1[j++] = list[i];
		}
	}

	j=0;
	for (i=0; i<NELEMS(toSort); i++) {
		if (toSort[i] < toSort[middle]) {
			newlist2[j++] = list[i];
		}
	}
	quick_sort(newlist1);
	quick_sort(newlist2);
	merge(newlist1, newlist2)
	print_list(sorted);
	return;
}



int main(int args, char * argv[]) {
	
	printf("there are %lu elements to sort\n", NELEMS(toSort));

	// somehow, the number of provided elements is getting reduced to 2...

	printf("sort1 gives: \n");
	selection_sort(toSort, sorted);
	printf("\n");


	printf("sort2 gives: \n");
	bubble_sort(toSort, sorted);
	printf("\n");


}
