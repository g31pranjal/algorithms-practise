#include <cstdio>

using namespace std;

int main() {

	int t,n;

	while(true) {
		scanf("%d", &t);

		if(t == -1)
			break;

		t = t-1;
		n = 1;

		while(t > 0) {
			t = t - n*6;
			n++;
		}

		if(t == 0)
			printf("Y\n");
		else
			printf("N\n");
	}

}