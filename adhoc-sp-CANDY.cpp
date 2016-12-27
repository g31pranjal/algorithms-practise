#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	while (true) {

		cin >> n ;

		if(n == -1)
			break;
		else {
			
			vector<int> a (n,0);
			int sum = 0, count = 0, avg = 0;

			for(int i=0;i<n;i++) {
				cin >> a[i];
				sum += a[i];
			}

			if(sum%n != 0)
				cout << "-1\n";
			else {
				avg = sum/n;

				for(int i=0;i<n;i++) {
					if(avg - a[i] > 0)
						count += (avg - a[i]);
				}

				cout << count << "\n";

			}

		}

	}

}