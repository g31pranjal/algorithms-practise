#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

	int t;
	cin >> t;

	int e, f, n, wt, t1, t2;
	vector< int > a;
	vector<pair<int,int> > coins;

	for(int z=0;z<t;z++) {

		cin >> e >> f >> n;
		wt = f - e;

		coins.clear();
		a.clear();
		a.resize(wt+1, -1 );

		a[0] = 0;

		for(int i=0;i<n;i++) {
			cin >> t1 >> t2;
			coins.push_back(make_pair(t1,t2));
		}

		// for(vector<pair<int,int> >::iterator k = coins.begin() ; k != coins.end() ;k++) {
		// 	cout << k->first << " : " << k->second << "\n";
		// }

		for(int j=1;j<=wt;j++) {
			for(vector<pair<int,int> >::iterator k = coins.begin() ; k != coins.end() ;k++) {
				if(j - k->second >= 0 && a[j - k->second] != -1 ) {
					if(a[j] == -1 || (k->first + a[j - k->second] < a[j]) )
						a[j] = a[j-k->second] + k->first;
				}
				//cout << "for " << j << " : " << a[j] << "\n";
			}

		}

		if(a[wt] != -1)
			cout << "The minimum amount of money in the piggy-bank is "<< a[wt] <<".\n";
		else 
			cout << "This is impossible.\n";


	}

}