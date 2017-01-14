#include <iostream>

using namespace std;

int main() {

	int t=0;

	cin >> t;

	for (int m = 0; m < t; ++m) {
		int r,c,s,cand;
		cin >> r >> c;

		int a[r][c];
		int calc[r][c];

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> a[i][j];
				if(i == 0) {
					calc[0][j] = a[0][j];
				}
				else {
					calc[i][j] = 0;
				}
			}
		}

		for (int i = 1; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				s = -1;
				for(int k = j-1; k <= j+1 ; k++) {
					if(k<0 || k >= c)
						continue;
					else {
						cand = a[i][j] + calc[i-1][k];
						if(s < cand) {
							s = cand;
						}
					}
				}
				calc[i][j] = s;
			}
		}

		int max = 0;

		for (int j = 0; j < c; ++j) {
			if(max < calc[r-1][j])
				max = calc[r-1][j];
		}


		cout << max << "\n";


	}

}