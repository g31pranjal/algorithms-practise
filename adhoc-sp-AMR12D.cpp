#include <cstdio>
#include <cstring>

using namespace std;

int main() {

	int t, l, i;
	char inp[100];
	bool pal;

	scanf("%d", &t);

	while(t--) {
		scanf("%s", inp);

		l = strlen(inp);

		pal = true;
		i = 0;

		while(i <= l-i-1) {
			if(inp[i] != inp[l-i-1]) {
				pal = false;
				break;
			}
			i++;
		}

		if(pal)
			printf("YES\n");
		else
			printf("NO\n");

	}


}