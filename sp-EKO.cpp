#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	long long n, m, tmp;
	scanf("%lld%lld", &n, &m);

	vector<int> a (n);

	for(int i=0;i<n;i++) {
		scanf("%lld", &tmp);
		a[i] = tmp;
	}

	sort(a.rbegin(), a.rend());

	// for(int i=0;i<n;i++) {
	// 	cout << a[i] << "\t";
	// }

	//cout << "\n" << (a.rbegin() == a.end()) << "\n"


	long long lo = 1;
	long long hi = 1000000000;
	long long gained, mid;

	while(lo < hi) {
		mid = lo + (hi-lo + 1)/2 ;
		
		gained = 0;
		for(int i=0;i<n;i++) {
			if(a[i] - mid > 0)
				gained += (a[i] - mid);
			else
				break;
		}

		//cout << "lo : " << lo << " hi : " << hi << " mid : " << mid << " gained " << gained << "\n";

		// NO
		if(gained < m) {
			hi = mid - 1;
		}
		else
			lo = mid;
	}

	cout << lo << "\n";



}