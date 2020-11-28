/*
* Copyright 2020 @LeafCode
*
* This code is for finding the maximum length of longest substring without
* repeating characters. This algorithm has time compelxity of O(n^2)
*
*/

#include <iostream>

using namespace std;

int length_of_longest_substr(string s) {

	int slen = s.length();
	int len = 0, maxlen = 0;
	bool visited[255] = {false};

	for (int i = 0; i < slen; i++) {

		for (int j = i; j < slen; j++) {
	
			if (visited[s[j]] == true) {

				break;	
			} else {

				maxlen = max(maxlen, j - i + 1);
				visited[s[j]] = true;
			}
		}
		visited[s[i]] = false;
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
