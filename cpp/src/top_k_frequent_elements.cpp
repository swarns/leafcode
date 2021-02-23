/*
* Copyright 2021 @LeafCode
*
* This code is for finding the top K frequent elements
* This algorithm has time compelxity of O(n * log(n))
*
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> top_k_frequent_elements (vector <int> & nums, int k) {

	vector <int> 			v;
	int				len = nums.size();
	map <int, int>			freq_map;
	multimap <int, int>		final_map;	
	multimap <int, int>:: iterator 	itr;
	int 				push_elem;

	for (int i = 0; i < len; i++) {

		freq_map[nums[i]]++;
	}

	for (itr = freq_map.begin(); itr != freq_map.end(); itr++) {

		final_map.insert (pair <int, int> (itr->second, itr->first) );
	}

	push_elem = final_map.size() - k;

	for (itr = final_map.begin(); itr != final_map.end(); itr++) {
		
		if (push_elem) {
			
			push_elem--;	
			continue;
		}

		v.push_back (itr->second);
	}

return v;
}


int main () {

	vector <int> 		nums;
	vector <int>		ret;

	nums.push_back(1);	
	nums.push_back(2);	
	nums.push_back(1);	
	nums.push_back(2);	
	nums.push_back(1);	
	nums.push_back(5);	
	nums.push_back(5);	
	nums.push_back(1);	
	nums.push_back(6);	
	nums.push_back(1);	

	ret = top_k_frequent_elements (nums, 3);

	for (int i = 0; i < ret.size(); i++)
		cout<<" "<<ret[i];

	cout<<endl;

return 0;
}
