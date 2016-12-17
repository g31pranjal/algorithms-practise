#include <vector>
#include <iostream>

using namespace std;

int main() {

	int cs;
	cin >> cs;

	for(int z=0;z<cs;z++) {

		int n,k,b,l;
		cin >> n >> k;

		int ar[k+1];
		int dp[k+1];
		int nm[k+1];

		for (int i = 1; i <= k; ++i) {
			cin >> ar[i]; 
			dp[i] = -1;
			nm[i] =  0;
		}

		dp[0] = 0;
		nm[0] = 0;


		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j<=i; j++) {

				if(ar[j] == -1 || dp[i-j] == -1 || (nm[i-j] + 1) > n  ) {
					continue;
				}
				else {
					b = dp[i-j] + ar[j];
					l = nm[i-j] + 1;
					if(dp[i] == -1){
						dp[i] = b;
						nm[i] = l;
					}
					else {
						if(dp[i] > b) { 
							dp[i] = b;
							nm[i] = l;
						}
						else if(dp[i] == b && nm[i] > l )
							nm[i] = l;
					}
				}	
			}
		}

		for (int i = 0; i <= k; ++i) {
			cout << dp[i] << ", " << nm[i] <<  "\t";
		}
		cout << "\n";

		cout << dp[k] << "\n";

	}

	return 0;
}
