#include <cstdio>

using namespace std;

int main() {

	int t, n, tmp;
	long long int min, global;

	scanf("%d", &t);

	for(int i=0;i<t;i++) {
		scanf("%d", &n);
		min = 0;
		global = 0;
		for(int j=0;j<n;j++) {
			scanf("%d", &tmp);
			min += tmp;
			if(min < global) {
				global = min;
			}
		}

		printf("Scenario #%d: %lld\n", i+1, -global + 1);

	}





}