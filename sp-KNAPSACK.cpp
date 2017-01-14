#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int srt(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}

int main() {

	int s, n, t1, t2, used;
	cin >> s >> n;

	vector< pair<int, int> > a;

	for(int i=0;i<n;i++) {
		cin >> t1 >> t2;
		a.push_back(make_pair(t1, t2));
	}

	sort(a.begin(), a.end(), srt);

	// for(int i=0;i<n;i++) {
	// 	cout << a[i].first << ", " << a[i].second << "\n";
	// }	

	vector< vector<long> > rslt (n+1 , vector<long> (s+1, -1) );

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=s;j++) {
			//cout << "i,j : " << i << ", " << j << "\n";			
			if(j==0 || i==0){
				rslt[i][j] = 0;
			}
			
			else {

				if( a[i-1].first <= j ) {
					rslt[i][j] = ( ( rslt[i-1][j - a[i-1].first] + a[i-1].second ) > rslt[i-1][j] ) ? ( rslt[i-1][j - a[i-1].first] + a[i-1].second ) : rslt[i-1][j];
				}
				else {
					rslt[i][j] = rslt[i-1][j];
				}
				
			}

		}

	}

	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<=s;j++) {
	// 		cout << rslt[i][j] << "\t";
	// 	}
	// 	cout << "\n";
	// }

	cout << rslt[n][s] << "\n";

}