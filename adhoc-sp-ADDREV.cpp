#include <iostream>

using namespace std;

int main() {
	int t;

	cin >> t;

	for(int z=0;z<t;z++) {
		int a, b, tmp;

		cin >> a >> b;

		int arev = 0, brev=0;

		while(a!=0) {
			arev = arev*10 + (a%10);
			a /= 10;
		}

		while(b!=0) {
			brev = brev*10 + (b%10);
			b /= 10;
		}

		int c = arev + brev;
		int crev = 0;

		while(c!=0) {
			crev = crev*10 + (c%10);
			c /= 10;
		}

		cout << crev << "\n";


	}
}