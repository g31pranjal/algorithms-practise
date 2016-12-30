#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int t, n, c, tmp1, hi, lo;
	long mid, lastcow, cows;
	vector<int> dist;
	scanf("%d", &t);

	for(int m=0;m<t;m++) {
		scanf("%d %d", &n, &c);
		dist.clear();
		dist.resize(n);

		for(int i=0;i<n;i++) {
			scanf("%d", &tmp1);
			dist[i] = tmp1;
		}

		sort(dist.begin(), dist.end());

		// for(int i=0;i<n;i++) {
		// 	printf("%d\t", dist[i]);
		// }
		// cout << "\n";

		hi = 1000000000;
		lo = 0;

		while(lo < hi) {
			mid = lo + (hi-lo + 1)/2;	
			// printf("lo : %d, hi : %d, mid : %d\n", lo, hi, mid);

			lastcow = dist[0];
			cows = 1;

			for(int d=1;d<dist.size() && cows < c;d++) {
				if(dist[d]-lastcow < mid)
					continue;
				cows++;
				lastcow = dist[d];
			}

			// cout << "adjusted cows :: " << cows << "\n";

			if(cows == c) 
				lo = mid;
			else 
				hi = mid - 1;

		}

		printf("%d\n", lo);


	}

}