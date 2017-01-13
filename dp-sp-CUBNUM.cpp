#include <cstdio>

using namespace std;

int a[110000], cb[50];

void countcubes() {
	for(int i=0;i<50;i++) {
		cb[i] = i*i*i;
	}
}

void dp() {
	countcubes();

	for(int i=1;i<=100010;i++) {
		a[i] = -1;
		for(int j=1;j<50 && i-cb[j] >= 0;j++) {
			if(a[i] == -1 || a[i-cb[j]] + 1 < a[i] )
				a[i] = a[i-cb[j]] + 1;
		}
	}
}

int main() {
	int n, z=1;
	dp();
	while(scanf("%d",&n)!=EOF) {		
		printf("Case #%d: %d\n", z++, a[n]);

	}
}