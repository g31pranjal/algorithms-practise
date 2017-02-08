#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

	char a[1000], b[1000], rslt[1000];
	memset(a, '\0', sizeof a);
	memset(b, '\0', sizeof b);
	memset(rslt, '\0', sizeof rslt);
	int ap, bp, rp, alen, blen;

	while(true) {

		if(scanf("%s", a) == EOF)
			break;
		
		scanf("%s", b);
		
		alen = (int)strlen(a);
		blen = (int)strlen(b);
		
		sort(a, a + alen);
		sort(b, b + blen);

		ap = 0, bp = 0, rp = 0;

		while(ap < strlen(a) && bp<strlen(b) ) {
			// printf("comp %d %d \n", ap, bp);
			if(a[ap] < b[bp])
				ap++;
			else if(a[ap] > b[bp])
				bp++;
			else {
				rslt[rp++] = a[ap];
				ap++;
				bp++;
			}
		}

		if(rp == 0)
			printf("\n");
		else {
			sort(rslt, rslt + rp-1);
			for(int i=0;i<rp;i++) 
				printf("%c", rslt[i]);
			printf("\n");
		}

		if(cin.eof())
			break;
	}
}