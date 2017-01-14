#include <cstdio>

using namespace std;

int main() {

	int t, n, rev;
	scanf("%d", &t);

	while(t--) {

		scanf("%d", &n);
		// printf(". %d\n", n);

		if(n%2 != 0 )
			printf("%d\n", n);
		else {

			rev = 0;
			n = n/2;

			while(n != 0) {
				rev = rev*2 + (n%2);
				n /= 2; 
			}

			printf("%d\n", rev);


		}


	}

}