/*
* Copyright 2020 @LeafCode
* 
* Given two strings, base and remove, return a version of base string
* where all instances of the rmeove string has been removed. remove string 
* might be of length 1 or more. Remove only non overlapping instances.
*
*/

#include <iostream>
#include <string>

using namespace std;

void without_string (string & base, string & remove) {

	int baselen = base.size();
	int removelen = remove.size();
	
	if (baselen == 0 || removelen == 0 || baselen < removelen)
		return;

	for (int i = 0; i <= baselen - removelen; i++) {

		if (base.compare (i, removelen, remove, 0, removelen) == 0) {

			base.erase (i, removelen);
		}
	}
}

int main () {

	string base = "Hello there";
	string remove = "llo";

	cout<<"base = "<<base<<", remove = "<<remove<<endl;
	without_string (base, remove);
	cout<<"calling without_string(base, remove)"<<endl;
	cout<<"base = "<<base<<", remove = "<<remove<<endl;

return 0;
}
