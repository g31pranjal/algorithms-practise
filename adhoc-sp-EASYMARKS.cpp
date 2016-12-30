#include <iostream>

using namespace std;

int main() {

	int t, n, k, sum, mrk;
	cin >> t;

	for(int m=0;m<t;m++) {
		cin >> n >> k;
		sum = (n+1)*k;

		for(int j=0;j<n;j++) {
			cin >> mrk;
			sum -= mrk;
		}

		cout << "Case " << (m+1) << ": " << sum << "\n";

	}

}