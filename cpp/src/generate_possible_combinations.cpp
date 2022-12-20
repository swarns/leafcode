/*
* Copyright 2022 @LeafCode
*
* Given a strings, we need to print all possible combinations 
* of its characters, the order doesnt matter. 
*
*/

#include <iostream>
#include <cmath>

using namespace std;

int main () {

	string str = "abcde";
	int len = str.size();
	int mask = 1;

	for (int i = 0; i < pow(2, len); i++) {

		for (int j = 0; j < len; j++) {

			if (i & (mask << j) ) {
				
				cout << str[j];
			}
		}
	cout << endl;
	}

	cout << endl;

return 0;
}
