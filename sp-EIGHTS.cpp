#include <iostream>

using namespace std;

int main() {


	int t;
	cin >> t;
	unsigned long long index, num;

	for (int m=0;m<t;m++) {
		cin >> index;
		num = 192 + (index-1)*250;
		cout << num << "\n";
	}
	


}