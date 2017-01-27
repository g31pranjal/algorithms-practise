#include <cstdio>

using namespace std;

int main() {

	int t, n, a[2], tmp;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		n--;
		a[0] = a[1] = ( (n/4) )*(-2);
		tmp = (n/4);
		n = n%4;
		if(n >= 0) {
			n--;
			a[0] = a[0] + 4*tmp + 1;
		}
		if(n >= 0) {
			n--;
			a[1] = a[1] + 4*tmp + 2;
		}
		if(n >= 0) {
			n--;
			a[0] = a[0] - 4*tmp - 3;
		}
		if(n >= 0) {
			n--;
			a[1] = a[1] - 4*tmp - 4;
		}


		printf("%d %d\n", a[0], a[1]);
 	}

}