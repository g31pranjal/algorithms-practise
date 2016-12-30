#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool srt(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {

	int t, n, p, q, cur, mx;
	vector<pair<int,int> > a;
	cin >> t;

	for(int m=0;m<t;m++) {

		int n;
		cin >> n;

		a.clear();

		for(int i=0;i<n;i++) {
			cin >> p >> q;
			a.push_back(make_pair(p, 1));
			a.push_back(make_pair(q, -1));
		}

		cur = 0, mx = 0;

		sort(a.begin(), a.end() , srt);

		for(int i=0;i<2*n;i++) {
			// cout << a[i].first << ", " << a[i].second << "\t" ;
			cur += a[i].second;
			if(cur > mx)
				mx = cur;
		}

		cout << mx << "\n";

	}
		

}