/*
* Copyright 2020 @LeafCode
*
* This code is for finding the maximum length of longest substring without
* repeating characters. This algorithm has time compelxity of O(n)
*
*/

#include <iostream>
#include <vector>
#define NO_OF_CHAR 256

using namespace std;

int length_of_longest_substr(string s) {

	int 	slen = s.length();
	int 	maxlen = 0;
	int 	i = 0;
	vector<int> last_index(NO_OF_CHAR, -1);

	for (int j = 0; j < slen; j++) {

		i = max (i, last_index[s[j]] + 1);
		maxlen = max (maxlen, j - i + 1);
		last_index[s[j]] = j;
	}

return maxlen;
}

int main() {

	string str;
	cout<<"enter string = ";
	cin>>str;
	cout<<"length_of_longest_sustring(str) = "<<length_of_longest_substr(str)<<endl;
	
return 0;
}
