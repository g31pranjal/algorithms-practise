#include <cstdio>
#include <map>

using namespace std;

int main() {

	int t, n, num;
	map<unsigned long long, unsigned long long> a;
	unsigned long long pointer, sum;
	scanf("%d", &t);

	for(int m=0;m<t;m++) {

		a.clear();
		scanf("%d", &n);
		//cin >> n;

		a[0] = 1;
		pointer = 0;
		sum = 0;

		for(int i=1;i<=n;i++) {
			scanf("%d", &num);
			// cin >> num;
			pointer += num;
			if(a.find(pointer) != a.end()) {
				sum += a[pointer];
				a[pointer]++;
			}
			else {
				a[pointer] = 1;
			}
		}

		printf("%lld\n", sum);

	}

}