/*
* Copyright 2020 @LeafCode
*
* Two strings are isomorphic if one to one mapping is possible for every character of the first string
* to every character of the second string. The time complexity of this code is O(n) and space complexity is O(n)  
*
*/

#include <iostream>

#include <iostream>
#include <string>

#define MAX_CHAR 256

using namespace std;

bool is_isomorphic (string & s, string & t) {

	if (s.size() != t.size())
		return false;

	int 	len = s.size();
	bool 	visited[MAX_CHAR] = {false};
	int	map[MAX_CHAR] = {-1};

	for (int i = 0; i < len; i++) {

		if (map[s[i]] == -1) {

			visited[s[i]] = true;
			map[s[i]] = t[i];
			


		} else if (map[s[i] != t[i]]) {
	
			return false;
		}
	}

return true;
}

int main () {

	string s = "egg";
	string t = "btt";

	if ( is_isomorphic (s, t) ) {

		cout<<s<<" and "<<t<<" are isomorphic"<<endl;

	} else {

		cout<<s<<" and "<<t<<" are not isomorphic"<<endl;
	}

return 0;
}
