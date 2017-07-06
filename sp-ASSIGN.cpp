#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

long dp[1024*1024*20];
int t, n;
int a[20][20];
int allmasked;

long count(int mask, int i) {
	// printf("\tin count %d, %d\n", mask, i);
	if(mask == allmasked)
		return 1;
	else if(i >= n) 
		return 0;
	else if(dp[mask*20 + i] != -1)
		return dp[mask*20 + i];
	else {
		long ways = 0;

		for(int j=0;j<n;j++) {
			if(a[i][j] == 1) {
				// jth student can have ith assignment
				if( (mask | (1 << j) ) != mask ) { 
					// he already doesnt have that assignment.
					ways += count(mask | (1 << j), i+1);
				}
			}
		}
		dp[mask*20 + i] = ways;
		return ways;
	}
}


int main() {

	scanf("%d", &t);
	
	while(t--) {
			
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		allmasked = (1 << n) - 1;

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				scanf("%d", &a[i][j]);
		}

		// cout << "reaching ..." << endl;

		cout << count(0,0) << endl;
	}
}