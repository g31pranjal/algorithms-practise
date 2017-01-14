#include <cstdio>

using namespace std;

int main() {

	int n, r, c;
	scanf("%d", &n);

	int dp[n][n] = {0};
	int a[n];

	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}


	for(int i=n;i>0;i--) {
		// printf("n : %d\n", i);

		if(i == n) {
			for(int j=0;j<i;j++)
				dp[j][j] = a[j]*i;
		}
		else {
			c = n-i;
			r = 0;
			for(int k=0;k<i;k++,r++,c++) {
				// printf("cords : %d, %d\n", r, c);
				dp[r][c] = (dp[r][c-1] + i*a[c]) > (dp[r+1][c] + i*a[r]) ? (dp[r][c-1] + i*a[c]) : (dp[r+1][c] + i*a[r]);
			}
		}
	}

	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<n;j++) {
	// 		printf("%d\t", dp[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%d\n", dp[0][n-1]);

}