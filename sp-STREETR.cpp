#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	int tmp;
	if(b > a) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while(a%b != 0) {
		tmp = a%b;
		a = b;
		b = tmp;
	} 
	return b;
}

int main() {

	int n, a[100000], pre;
	scanf("%d", &n);

	scanf("%d", &a[0]);

	for(int i=1;i<n;i++) {
		scanf("%d", &a[i]);
		a[i-1] = a[i]-a[i-1];
	}

	pre = a[0];

	for(int i=1;i<n-1;i++) {
		pre = gcd(pre, a[i]);
	}

	int count = 0;

	for(int i = 0;i<n-1;i++) {
		count += ((a[i]/pre) - 1);
	}

	printf("%d\n", count);

}