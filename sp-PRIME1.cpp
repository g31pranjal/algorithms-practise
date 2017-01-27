#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main() {

	bool seed[40000];
	bool sgmt[100000];

	int t, m, n, l, ind;
	scanf("%d", &t);

	while(t--) {
		memset(seed, false, sizeof seed);
		memset(sgmt, false, sizeof sgmt);

		scanf("%d %d", &m, &n);

		for(int i=2;i<=sqrt(n);i++) {
			if(seed[i])
				continue;
			for(int j=1;j*i<=sqrt(n);j++)
				seed[j*i] = true;
	
			l = m/i;
			l = (l*i) < m ? l+1 : l;
			l = (l==1) ? 2 : l;

			while(l*i <=n ) {
				ind = l*i - m;
				sgmt[ind] = true;
				l++;
			}
		}

		for(int i=m;i<=n;i++) {
			if(!sgmt[i-m] && i != 1)
				printf("%d\n", i);
		}
		printf("\n");

	}

}