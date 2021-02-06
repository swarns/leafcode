/*
* Copyright 2020 @LeafCode
* 
* find the split point in an array where sum of both halves are equal
* the time complexity of this code is O(n)
*
*/

#include <iostream>

using namespace std;

int split_array_in_equal_sum_half (int *arr, int size) {
	
	int split_point = -1;
	int sum = 0;
	int lsum = 0;
	int rsum = sum;

	if (arr == NULL || size == 0 || size == 1)
		return -1;
	
	for (int i = 0; i < size; i++) {

		sum += arr[i];
	}

	rsum = sum;

	for (int i = 0; i < size; i++) {
	
		lsum += arr[i];
		rsum -= arr[i];

		if (lsum == rsum) {		

			return i;			
		} 
	}

return split_point; 
}


int main () {

	int arr[] = {4, 6, 9, 1};
	int size = 4;
	int ret = 0;
	
	ret = split_array_in_equal_sum_half (arr, size);

	if (ret == -1) {
		
		cout<<"no split point to divide array in equal sum half"<<endl;
	} else {

		cout<<"split point "<<ret<<" to divide array in equal sum half"<<endl;
	}


return 0;
}
