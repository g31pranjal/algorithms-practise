#include <cstdio>

using namespace std;

int main() {

	long long int t, n, tmp, rem;
	scanf("%lld\n", &t);

	while(t--) {

		scanf("%lld", &n);

		rem = 0;

		for(int i =0;i<n;i++) {
			scanf("%lld", &tmp);
			rem = ((tmp%n) + rem) % n;
			// printf("rem : %lld\n", rem);
		}

		if(rem == 0)
			printf("YES\n");
		else
			printf("NO\n");
		
	}



}