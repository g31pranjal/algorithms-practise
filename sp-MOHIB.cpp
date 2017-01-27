#include <cstdio>

using namespace std;

int main() {

	long long int t, n, avg, total, hgt, x;
	scanf("%lld", &t);

	while(t--) {

		scanf("%lld %lld", &x, &avg);

		n = avg - x;
		total = n*(avg+1);

		hgt = total - (n-1)*n/2;

		printf("%lld\n", hgt);


	}


}
