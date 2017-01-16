#include <cstdio>

using namespace std;

int main() {

	int t;
	long long int n, cn;
	scanf("%d", &t);

	for(int i=0;i<t;i++) {

		scanf("%lld", &n);

		cn = ((8*n)%11);
		
		if(cn == 0)
			printf("0\n");
		else
			printf("%lld\n", 11 - cn);

	}

}