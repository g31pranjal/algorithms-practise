#include <cstdio>
#include <vector>

using namespace std;

int main() {

	int t, n;
	scanf("%d", &t);
	vector<pair<long long int, long long int> > a (20, make_pair(0, 0));

	while(t--) {
		scanf("%d", &n);

		int max = 1048576;
		int exp = 20;

		while(exp >= 0) {
			if(n/max == 1) {
				a[exp].second++;
				n -= max;
			}
			else
				a[exp].first++;
			max /= 2;
			exp--;
		}
	}

	long long int unit = 1;
	long long int ans = 0;

	for(int i=0;i<20;i++) {
		ans += (a[i].first*a[i].second)*unit;
		unit *= 2;
	}

	printf("%lld\n", ans);
}