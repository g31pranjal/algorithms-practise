#include <cstdio>

using namespace std;

int main() {

	int t, n, a[1000], l, r;
	scanf("%d", &t);
	bool fl, fr, dn;

	while(t--) {
		scanf("%d", &n);

		for(int i=0;i<n;i++) 
			scanf("%d", &a[i]);


		for(int i=0;i<n/2;i++) {
			l = i;
			r = n - 1 - i;
			fl = (a[l] == l || a[l] == r) ? true : false;
			fr = (a[r] == l || a[r] == r) ? true : false;
			dn = true;
			for(int j = l+1;j<r;j++) {
				if(a[j] == l || a[j] == r)
					if(!fl) {
						a[l] = a[j] + a[l];
						a[j] = a[l] - a[j];
						a[l] = a[l] - a[j];
						fl = true;
					}
					else if(!fr) {
						a[r] = a[j] + a[r];
						a[j] = a[r] - a[j];
						a[r] = a[r] - a[j];
						fr = true;	
					}
			}

			if(!fl || !fr){
				dn = false;
				printf("NO\n");
				break;
			}

		}

		if(dn)
			printf("YES\n");

	}

}