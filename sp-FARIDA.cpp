#include <cstdio>

using namespace std;

int main() {

	int t, n;
	scanf("%d", &t);
	long long int val[10000], dp[11000];

	for(int m=1;m<=t;m++) {

		scanf("%d", &n);

		for(int i=0;i<n;i++)
			scanf("%lld", &val[i]);

		dp[0] = dp[1] = 0;

		for(int i=0;i<n;i++) {
			dp[i+2] = -1;
			for(int j=i-2;j>=-2;j--) {
				if(dp[i+2] == -1 || val[i] + dp[j+2] > dp[i+2])
					dp[i+2] = dp[j+2] + val[i];
			}
			dp[i+2] = dp[i+2] > dp[i+1] ? dp[i+2] : dp[i+1];
		}

		// for(int i=0;i<n+2;i++)
		// 	printf("%d\t", dp[i]);
		// printf("\n");

		printf("Case %d: %lld\n", m, dp[n+1]);


	}


}