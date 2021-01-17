#include <iostream>
#include <string>

using namespace std;

int main () {

	string str = "2194dmlkwqmd::l;[[/[,kij20nsasabcmm";
	int len = str.length();
	int freq_arr[128] = {0};

	for (int i = 0; i < len; i++) {

		freq_arr[str[i]]++;
	}

	for (int i = 0; i < 128; i++) {

		cout<<(char) i<<" = "<<freq_arr[i]<<endl;
	}

return 0;
}
