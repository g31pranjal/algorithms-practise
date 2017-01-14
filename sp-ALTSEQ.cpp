#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int size, curr;
	cin >> size;

	int a[size];
	int p[size], n[size];

	for(int i=0;i<size;i++) {
		cin >> a[i];
		p[i] = -1;
		n[i] = -1;
	}

	for(int i=0;i<size;i++) {
		n[i] = 1;
		p[i] = -1;
		curr = a[i];
		if(curr > 0) {
			for(int j=0;j<i;j++) {
				if( a[j] < 0 && ((int)abs(a[j]) < (int)abs(a[i]) ) && n[i] < n[j] + 1 ) {
					p[i] = j;
					n[i] = n[j] + 1;
				}
			}
		}
		else if (curr < 0) {
			for(int j=i-1;j>=0;j--) {
				if( a[j] > 0 && ( (int)abs(a[j]) < (int)abs(a[i]) ) && n[i] < n[j] + 1 ) {
					p[i] = j;
					n[i] = n[j] + 1;
				}
			}
		}
	}

	int max = 0;

	for(int i=0;i<size;i++) {
		if(max < n[i])
			max = n[i];
	}

	// for(int i=0;i<size;i++) {
	// 	cout << a[i] << " : " << n[i] << "," << p[i] << "\t";
	// }

	cout << max << "\n";

	return 0;


}
