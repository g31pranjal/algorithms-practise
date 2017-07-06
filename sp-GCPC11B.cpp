#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int p, t, n, l, r, k=0;
	bool match = false;
	char a[2000], b[2000];
	int c[2][2000];
	scanf("%d", &p);

	for(int z=0;z<p;z++) {
		match = false;
		scanf("%d", &n);
		scanf("%s", a);
		scanf("%s", b);
	
		// for(int i=0;i<n;i++) {
		// 	cout << a[i] << "\t";
		// }
		// cout << "\n";

		t = (n+1)>>1;
		r = 0;

		// printf("threshold :: %d\n", t);

		for(int i=0;i<n;i++) {
			k = (k+1)%2;
			for(int j=0;j<n;j++) {
				if(abs(a[i] - b[j]) <= 1 ){
					if(i==0 || j==0) { 
						c[k][j] = 1;
					}
					else {
						c[k][j] = c[(k+1)%2][j-1] + 1;
					}
					if(c[k][j] > r)
						r = c[k][j];
				}
				else 
					c[k][j] = 0;
			}
		}

		if(r >= t)
			printf("POSITIVE\n");
		else 
			printf("NEGATIVE\n");
	}
}

