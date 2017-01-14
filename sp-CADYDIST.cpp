#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

	long long int n, ans;
	long long int a[100000], b[100000];

	while(true) {

		scanf("%lld", &n);

		if(n == 0)
			break;

		for(int i=0;i<n;i++) {
			scanf("%lld", &a[i]);
		}

		for(int i=0;i<n;i++) {
			scanf("%lld", &b[i]);
		}
		
		sort(a, a + n);
		sort(b, b + n);

		ans = 0;

		for(int i=0;i<n;i++) {
			ans += a[i]*b[n-1-i];
		}

		printf("%lld\n", ans);


	}

}