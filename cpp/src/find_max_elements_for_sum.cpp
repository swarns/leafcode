/*
* Copyright 2022 @LeafCode
*
* Given an integer array nums and a target sum, one needs to find the maximum elements 
* from the array which adds up to that sum
* eg: arr[1, 2, 3, 5, 5], target = 10, so possible combinations are 2 + 3 + 5 = 10 & 5 + 5 = 10, 
* so max no of elements which adds up to 10 is 3
* 
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int find_max_elements_count (vector <int>& arr, int target) {

	int max_count = 0;
	int count = 0;
	int sum = 0;
	int mask = 1;

	for (int i = 0; i < pow(2, arr.size()); i++) {

		for (int j = 0; j < arr.size(); j++) {

			if (i & (mask << j)) {

				sum += arr[j];
				count++;
			}	
		}

		if (sum == target) {

			if (max_count < count) {

				max_count = count;
			}
		}
		count = 0;
		sum = 0;

	}

return max_count;
}

int main () {

	int a[] = { 1, 2, 3, 5, 5};
        int n = sizeof(a) / sizeof(int);
        vector <int> arr(a, a + n);

	cout << "find_max_elements_count(arr, target) = " << find_max_elements_count (arr, 10) << endl;

return 0;
}
