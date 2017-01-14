#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {

	int t, n, k, min;
	scanf("%d", &t);
	int inp[20000];

	while(t--) {
		memset(inp, 0, sizeof inp);

		scanf("%d %d", &n, &k);

		for(int i=0;i<n;i++) {
			scanf("%d", &inp[i]);
		}

		sort(inp, inp + n);

		if(k == 1 )
			printf("0\n");
		else if (k >=n) {
			printf("%d\n", inp[n-1] - inp[0]);
		}
		else {
			min = 1000000000;
			for(int i = k-1;i<n;i++) {
				if(inp[i] - inp[i-k+1] < min)
					min = inp[i] - inp[i-k+1];
			}
			printf("%d\n", min);
		}


	}

}