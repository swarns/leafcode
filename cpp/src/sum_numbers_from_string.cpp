/*
* Copyright 2020 @LeafCode
* 
* Given an string which contains numbers as well as other non numeric characters
* you need to sum all the numbers and return the int from function.
*
*/

#include <iostream>
#include <string>

using namespace std;

int sum_numbers_from_string (string str) {

	int 	sum = 0;
	int 	ret = 0;
	int 	len = str.size();
	int 	contflag = 0;

	if (len == 0)
		return 0;

	for (int i = 0; i < len; i++) {

		if (str[i] >= 48 && str[i] <= 57) {
	
			contflag = 1;	
			sum = 10 * sum + (str[i] - 48);
				
		} else {

			ret += sum;
			sum = 0;
			contflag = 0;
			continue;
		}

	}

	if (sum)
		ret += sum;


return ret;
}


int main () {

	string s = "hex123d,67,/,mxn21mmsk56";

	cout<<" digits sum in string = "<<sum_numbers_from_string (s)<<endl;

return 0;
}
