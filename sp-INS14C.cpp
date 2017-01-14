#include <iostream>
#include <vector>

using namespace std;

int main() {

	int t, n, k, j;
	bool rem;
	vector<char> a;
	cin >> t;

	for(int m=0;m<t;m++) {

		cin >> n >> k;
		a.clear();
		a.resize(n, '\0');

		for(int i=0;i<n;i++) {
			cin >> a[i];
		}

		for(int i = n;i>k;i--) {
			rem = false;
			if((n-i)%2 == 0) {
				// minimize
				for(j=0;j<i;j++) {
					if(a[j] == '1') {
						rem = true;
						break;
					}
				}
			}
			else {
				for(j=0;j<i;j++) {
					if(a[j] == '0') {
						rem = true;
						break;
					}
				}
			}

			if(rem)
				a.erase(a.begin() + j);
			else
				a.erase(a.end() - 1);

		}

		for(int i=0;i<a.size();i++) {
			cout << a[i];
		}
		cout << "\n";


	}

}