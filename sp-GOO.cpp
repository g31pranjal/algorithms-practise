#include <cstdio>

using namespace std;

int main() {

	int t, n;
	long long int ex2, nm;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		ex2 = 1;
		for(int i=1;i<n;i++) {
			ex2 *= 2;
		}
		nm = ex2 + (n-1)*(ex2/2);

		printf("%lld %lld\n", ex2, nm);



	}


}
