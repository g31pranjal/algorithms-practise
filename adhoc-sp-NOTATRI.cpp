#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	vector<int> a;

	while(true) {
		//cout << "case \n";
		cin >> n;
		if(n == 0)
			break;

		a.clear();
		a.resize(n, -1);

		for(int i=0;i<n;i++) {
			cin >> a[i];
		}

		sort(a.begin(), a.end());

		//cout << "n : " << n << "\n";

		// for(int i=0;i<n;i++) {
		// 	cout << a[i] << "\t";
		// }

		long long int count = 0, mul;
		int k=0;

		for(int i=n-1;i>=2;i--) {
			// cout << "i : \t a[" << i << "] : " << a[i] << "\n";
			k = 0;
			for(int j=i-1;j>=1&&j>=k;j--) {
				// cout << "j : \t a[" << j << "] : " << a[j] << "\n";
				while(j>k && a[j]+a[k] < a[i] ){
					// cout << "k : \t a[" << k << "] : " << a[k] << "\t increasing k\n";
					k++;
				}
				// cout << " value of k : " << k << "\n";
				count += (k);
			}
			count += (k)*(k-1)/2;
			// cout << "count >> " << count << "\n";
		}
		cout << count << "\n";


	}

}