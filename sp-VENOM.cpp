#include <cstdio>

using namespace std;

int main() {

	int t, h, p, a, ans;
	scanf("%d", &t);

	while(t--) {

		scanf("%d %d %d", &h, &p, &a);

		int  c = 3*p - 8*h + 4*a;
		int lc = 4*(p-a);
		int qc = p;

		for(int i=1;;i=i+2) {

			ans = i*i*qc + i*lc + c;
			if(ans >= 0) {
				printf("%d\n", i);
				break;
			}

		}


	}

}