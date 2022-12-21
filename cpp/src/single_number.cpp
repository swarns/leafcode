/*
* Copyright 2022 @LeafCode
*
* Given an integer array nums where every element appears three times except for one, which appears exactly once.
* Find the single element and return it.
* You must implement a solution with a linear runtime complexity and use only constant extra space.
*
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int single_number (vector <int> &v) {


	unordered_map <int, int> um;
	
	for (int i = 0; i < v.size(); i++) {

		um[v[i]]++;
	}

	for (unordered_map <int, int>::iterator i = um.begin(); i != um.end(); i++) {

		if (i->second == 1)
			return i->first;
	}

return 0;
}

int main () {

	int arr[] = { 1, 2, 3, 3, 1, 2, 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(int);
	vector <int> v(arr, arr + n);
	
	cout << "single_number(v) = " << single_number(v) << endl;

return 0;
}
