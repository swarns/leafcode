/*
* Copyright 2023 @LeafCode
* 
* This code is for printing all the combinations of intergers in a given array.
* the time complexity of this code is O(n * 2^n)
*/
#include <iostream>
#include <set>

#define SIZE 4

using namespace std;

void print_sets(set < set <int> > &v) {

	set < set <int> >::iterator itrs;
	set <int>::iterator itr;

	for (itrs = v.begin(); itrs != v.end(); itrs++) {
		
		cout << "[ ";
		for (itr = itrs->begin(); itr != itrs->end(); itr++) {
	
			cout << *itr << " ";
		}
		cout << " ] ";
	}
	cout << endl;
}

void combine (int arr[], int i, set <int> & subset, set < set <int> > & subsets) {

	if (i == SIZE) {
		
		subsets.insert(subset);
	} else {

		subset.insert(arr[i]);
		combine (arr, i + 1, subset, subsets);
		subset.erase(arr[i]);
		combine (arr, i + 1, subset, subsets);
	}
}

set < set <int> > get_subsets(int arr[]) {

	set < set <int> > subsets;
	set <int> subset;

	combine (arr, 0, subset, subsets);

	return subsets;
}

int main () {

	int arr[] = {1, 2, 3, 4};
	set < set <int> > v;
	
	v = get_subsets(arr);	
	print_sets(v);	

return 0;
}
