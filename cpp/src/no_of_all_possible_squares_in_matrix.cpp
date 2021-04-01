/*
* Copyright 2021 @LeafCode
*
* This code is for count all possible squares in a matrix. 
*
*/

#include <iostream>

using namespace std;

int no_of_all_possible_squares_in_matrix (int size) {

	if (size == 0)
		return 0;

	return (size * size) + no_of_all_possible_squares_in_matrix (size - 1);
}

int main () {

	int msize = 12;

	cout<<"no_of_all_possible_squares_in_matrix ("<<msize<<") = "<<no_of_all_possible_squares_in_matrix (msize)<<endl;

return 0;
}
