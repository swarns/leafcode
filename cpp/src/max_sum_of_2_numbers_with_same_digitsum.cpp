/*
* Copyright 2021 @LeafCode
*
* Given a vector with intergers, find the maximum possible sum of two numbers whose digitsum is same.
* if there are no possible two numbers then return -1
*
* eg: 
* v = [41, 32, 54, 81, 72] then the answer would be 153 
*
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int digit_sum (int num) {

	int 	dsum = 0;
	int 	ret = 0;

	while (num) {

		ret = num % 10;
		dsum += ret;
		num = num / 10;
	}

return dsum;
}

int maxsum_of_2_numbers_with_same_digitsum (vector <int> & nums) {

	int 						len = nums.size();
	unordered_map < int, vector<int> >		m;
	unordered_map < int, vector<int> >:: iterator 	itr;
	int 						tmp = 0;
	int 						max = -1;
	

	for (int i = 0; i < len; i++) {

		if ( m[digit_sum(nums[i])].size() < 2 ) {

			m[digit_sum(nums[i])].push_back (nums[i]);

			if ( m[digit_sum(nums[i])][0] < m[digit_sum(nums[i])][1] ) {

				tmp = m[digit_sum(nums[i])][0];
				m[digit_sum(nums[i])][0] = m[digit_sum(nums[i])][1];
				m[digit_sum(nums[i])][1] = tmp;
			}

		} else {

			if ( m[digit_sum(nums[i])][0] < nums[i] ) {
		
				m[digit_sum(nums[i])][0] = nums[i];

				if ( m[digit_sum(nums[i])][0] < m[digit_sum(nums[i])][1] ) {

					tmp = m[digit_sum(nums[i])][0];
					m[digit_sum(nums[i])][0] = m[digit_sum(nums[i])][1];
					m[digit_sum(nums[i])][1] = tmp;
				}

			}

		}
	}

	for (itr = m.begin(); itr != m.end(); itr++) {

		if (itr->second.size() == 2) {

			if ( max < (itr->second[0] + itr->second[1]) )
				max = itr->second[0] + itr->second[1];
		}
	}

return max;
}


int main () {

	vector <int> nums = {23, 14, 90, 44, 54};

	cout<<"max sum of two digits for same digitsum = "<<maxsum_of_2_numbers_with_same_digitsum (nums)<<endl;


return 0;
}
