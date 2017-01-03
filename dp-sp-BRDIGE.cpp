#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool srtfunc(pair<int, int> a, pair<int, int> b) {
	//return a.first < b.first && a.second < b.second;

	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

int main() {

	int t, n, tmp;
	vector<int> a, c, d;
	vector<pair<int, int> > pr;
	pair<int, int> tp;
	cin >> t;

	for(int m=0;m<t;m++) {

		cin >> n;
		a.clear();
		c.clear();
		d.clear();
		pr.clear();
		a.resize(n, -1);
		c.resize(n, -1);
		d.resize(n, -1);

		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++){
			cin >> tmp;
			pr.push_back(make_pair(a[i], tmp));
		}

		sort(pr.begin(), pr.end(), srtfunc);
		
		// for(int i=0;i<pr.size();i++) 
		// 	for(int j=0;j<pr.size();j++) 
		// 		if(pr[i].second <= pr[j].second ) {
		// 			tp = pr[i];
		// 			pr[i] = pr[j];
		// 			pr[j] = tp;
		// 		}
		
		// for(int i=0;i<pr.size();i++) 
		// 	for(int j=0;j<pr.size();j++) 
		// 		if(pr[i].first <= pr[j].first ) {
		// 			tp = pr[i];
		// 			pr[i] = pr[j];
		// 			pr[j] = tp;
		// 		}
		

		// for(int i=0;i<n;i++)
		// 	cout << pr[i].first << "." << pr[i].second << "\t";
		// cout << "\n";

		int max = 1;

		for(int i=0;i<n;i++) {
			c[i] = 1;
			d[i] = -1;
			for(int j=i-1;j>=0;j--) {
				if(pr[j].first <= pr[i].first && pr[j].second <= pr[i].second && c[j] + 1 >= c[i]) {
					c[i] = c[j]+1;
					d[i] = j;
					if(c[i] > max)
						max = c[i];
				}
			}
		}

		// for(int i=0;i<n;i++)
		// 	cout << c[i] << "." << d[i] << "\t";
		// cout << "\n";

		cout << max << "\n";




	}


}