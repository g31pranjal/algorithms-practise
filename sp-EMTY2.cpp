#include <cstdio>
#include <cstring>

using namespace std;

int main() {

	int t, count, l;
	char a[200000];
	scanf("%d", &t);

	for(int m=1;m<=t;m++) {

		scanf("%s", a);
		l = strlen(a);
		count = 0;

		for(int i=0;i<l;i++) {
			if(a[i] == '1')
				count += 2;
			else if(a[i] == '0')
				count--;
		}

		if(count == 0 && a[l-1] == '0' && a[l-2] == '0')
			printf("Case %d: yes\n", m);
		else
			printf("Case %d: no\n", m);

	}

}