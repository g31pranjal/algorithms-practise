#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n, m;
	char a[100], b[100], c[100];

	scanf("%d%d", &n, &m);

	for(int i=0;i<m;i++) {
		a[i] = '#';
		b[i] = '.';
		c[i] = '.';

	}

	b[m-1] = '#';
	c[0] = '#';


	a[m] = '\0';
	b[m] = '\0';
	c[m] = '\0';

	for(int i=0;i<n;i++) {
		if(i%2 == 0)
			printf("%s\n", a);
		else {
			if(i%4 == 1)
				printf("%s\n", b);
			else if(i%4 == 3)
				printf("%s\n", c);
		}
	}

}