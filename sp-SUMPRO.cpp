#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

	int t;
	cin >> t;
	long long int n, x, hi, lo, sum;

	for(int z=0;z<t;z++) {
		sum = 0;
		cin >> n;
		

		// for (int i=1;i<=n;i++) {
		// 	printf("i %d : %d\n", i , (n/i));
		// }

		for(int j=1;j<=(int)sqrt(n);j++) {
			x = n/j;
			sum = (sum + (x*j)%1000000007 )%1000000007 ;

			//cout << "j : " << j << "\n";

			if(j != n/j) {
			//if(x != (int)sqrt(n)) {
				//cout << "going in\n";

				hi = (n/j)*(n/j + 1)/2;
				lo = (n/(j+1))*(n/(j+1) + 1)/2;
				sum = (sum + (((hi - lo)*j)%1000000007  )  ) % 1000000007;
			}

		}	
		cout << sum << "\n";
	}


}