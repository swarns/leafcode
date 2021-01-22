/*
* Copyright 2020 @LeafCode
*
* This code is for finding if the number is prime of not
* with best possible time complexity. Time complexity O(n)
*
*/

#include <iostream>

using namespace std;

bool is_prime (long int num) {

	if (num == 0 || num == 1) 
		return false;

	if (num == 2 || num == 3)
		return true;

	if (num < 0) {

		num = -num;
	}
	
	if (!(num % 2))
		return false;
	

	for (int i = 3; i <= num/2; i += 2) {	

		if (!(num % i))
			return false;
	}

return true;
}

int main () {

	long int num;
	
	cout<<"enter number: ";
	cin>>num;

	cout<<"number "<<num<<" is ";
	
	if (is_prime (num))
		cout<<"prime"<<endl;
	else
		cout<<" not prime"<<endl;

return 0;
}
