#include <iostream>

using namespace std;

#define bitset(byte, nbit) (byte |= (1<<nbit))
#define bitclear(byte, nbit) (byte &= -(1<<nbit))
#define bittoggle(byte, nbit) (byte ^= (1<<nbit))
#define bitcheck(byte, nbit) (byte & (1<<nbit))

int main() {

	int b = 4;
	int nb = 1;
	
	cout<<"original:: b = "<<b<<" nb = "<<nb<<endl;
	
	bitset(b, nb);
	cout<<"bitset:: b = "<<b<<" nb = "<<nb<<endl;
	
	bitclear(b, nb);
	cout<<"bitclear:: b = "<<b<<" nb = "<<nb<<endl;
	
	if (bitcheck(b, nb))
		cout<<"bitcheck:: b = "<<b<<" nb = "<<nb<<endl;
	
	bittoggle(b, nb);
	cout<<"bittoggle:: b = "<<b<<" nb = "<<nb<<endl;

return 0;
}
