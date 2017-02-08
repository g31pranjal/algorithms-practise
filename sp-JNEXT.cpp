#include <cstdio>
#include <vector>

using namespace std;

int main() {

	int t, n, dg;
	int num[1000000];
	vector< vector<int> > a;
	bool fnd;

	scanf("%d", &t);

	while(t--) {
		fnd = false;
		a.clear();
		a.resize(10, vector<int> () );

		scanf("%d", &n);
		for(int i=0;i<n;i++) {
			scanf("%d", &num[i]);
		}

		// printf("read all\n");

		for(int i=0;i<n;i++) {
			dg = num[n-1-i];
			a[dg].push_back(n-1-i);

			for(int j=dg+1;j<=9;j++) {
				if(a[j].size() > 0) {
					fnd = true;
					for(int k=0;k<n-1-i;k++){
						printf("%d", num[k]);
					}
					printf("%d", j);
					a[j].pop_back();
					for(int l=0;l<10;l++) {
						while(a[l].size() != 0) {
							printf("%d", l);
							a[l].pop_back();
						}
					}
					printf("\n");
				}
				if(fnd)
					break;
			}
			if(fnd)
				break;
		}
		if(!fnd)
			printf("-1\n");
	}
}