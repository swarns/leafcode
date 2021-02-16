/*
* Copyright 2021 @LeafCode
* 
* This code is for printing all the permutations of characters in a given string.
* the time complexity of this code is O(n * n!)
*/

#include <iostream>

#include <iostream>
#include <string>

using namespace std;

void permute (string s, int l, int r) {

	if (l == r)
		cout<<" "<<s;

	for (int i = l; i < r; i++) {

		swap (s[l], s[i]);
		permute (s, l + 1, r);
		swap (s[l], s[i]);
	}
}

int main () {

	string s = "abc";

	permute (s, 0, s.size());
	cout<<endl;

return 0;
}
