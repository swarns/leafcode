/*
* Copyright 2021 @LeafCode
*
* This code is to pass an array as a reference.
* As array cannot be passed as a reference, so wrapping it aronud a structure variable
* and passing the strucutre variable using reference does the work. 
*
*/

#include <iostream>

using namespace std;

#define SIZE 10

typedef struct _wrap_array {

	int arr[SIZE];

}wrap_array;

void arr_ref_fun (wrap_array & ob) {

	for (int i = 0; i < SIZE; i++) {

		cout<<" "<<ob.arr[i];
	}
	cout<<endl;
}


int main () {

	wrap_array ob;

	for (int i = 0; i < SIZE; i++)
		ob.arr[i] = i;

	arr_ref_fun (ob);


return 0;
}
