#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool psort(pair<int, int> a, pair<int, int> b) {
	return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main() {

	int t, n, s, f, num;
	vector< pair<int,int >  > sch;
	pair<int,int > last;
	cin >> t;

	for (int m = 0; m < t; ++m) {
		
		cin >> n;
		sch.clear();

		for(int i=0;i<n;i++) {
			cin >> s >> f;
			sch.push_back(make_pair(s,f) );
		}

		sort(sch.begin(), sch.end(), psort);

		num = 1;
		last = sch[0];

		for(int j=1;j<n;j++) {
			if(sch[j].first >= last.second) {
				last = sch[j];
				num++;
			}
		}

		cout << num << "\n";


		// for(int i=0;i<n;i++) {
		// 	cout << sch[i].first << ", " << sch[i].second << "\t";
		// }
		// cout << "\n";

	}

}