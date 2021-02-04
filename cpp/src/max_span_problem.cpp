/*
* Copyright 2020 @LeafCode
* 
* Considering the leftmost and rightmost appearance of same value in an arry
* we will say that the span is the number of elements between two inclusive.
* Return the largent span found in the given array.
*
*/

#include <iostream>

using namespace std;

int max_span(int *arr, int size) {

	int maxspanlen = 0;
	int len = 0;

	if (arr == NULL || size == 0)
		return 0;

	for (int i = 0; i < size; i++) {

		for (int j = size - 1; j > i; j--) {
		
	
			if (arr[i] == arr[j]) {
			
				len = j - i + 1;
				break;
			}
		}
		if (maxspanlen < len) {

			maxspanlen = len;
		}
	}

return maxspanlen;
}

int main () {

	int arr[] = {1, 4, 2, 1, 4, 4, 4};
	int size = 7;

	cout<<"max_span(arr) = "<<max_span (arr, size)<<endl;

return 0;
}
