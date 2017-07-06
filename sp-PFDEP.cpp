#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n=0, m=0, rule, fr, entr, flag;

	cin >> n >> m;

	// indices 1 to n
	vector<int> a[n+1];
	vector<int> done (n+1, 0);

	for(int i=0;i<m;i++) {
		cin >> rule;
		cin >> entr;

		for(int j=0;j<entr;j++) {
			cin >> fr;
			a[rule].push_back(fr);
		}
	}

	while(true) {
		flag = 0;
		for(int i=1;i<=n;i++) {
			if(a[i].size() == 0 && done[i] == 0) {
				flag = 1;
				done[i] = 1;
				cout << i << " ";
				for(int j=1;j<=n;j++) {
					if(done[j] == 0) {
						for(int k=0;k<a[j].size();k++) {
							if (a[j][k] == i) {
								a[j].erase(a[j].begin() + k);
								break;
							}
						}
					}
				}
				break;

				// // updated list 
				// for(int p=0;p<=n;p++) {
				// 	cout << p << " : ";
				// 	for(int q=0 ; q<a[p].size() ; q++) {
				// 		cout << a[p][q] << "\t";
				// 	}
				// 	cout << "\n";
				// }


			}
		}

		if (flag == 0)
			break;
	}

	// for(int i=0;i<=n;i++) {
	// 	cout << i << " : ";
	// 	for(int j=0 ; j<a[i].size() ; j++) {
	// 		cout << a[i][j] << "\t";
	// 	}
	// 	cout << "\n";
	// }

}