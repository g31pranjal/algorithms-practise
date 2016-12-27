#include <iostream>

using namespace std;

int main() {

	int t;
	cin >> t;

	for(int m=0;m<t;m++) {

		int n;
		cin >> n;
		int sum = 0;
		while(n>0) {
			sum += (n/5);
			n = n/5;
		}

		cout << sum << "\n";

	}

}