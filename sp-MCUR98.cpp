#include <cstdio>
#include <cstring>

using namespace std;

int digitsum(int num) {
	int sum = 0;
	while(num != 0) {
		sum += (num%10);
		num /= 10;
	}
	return sum;
}

int main() {

	bool a[1000000];
	memset(a, false, sizeof a);
	int n;

	for(int i=1;i<1000000;i++) {
		if(a[i])
			continue;
		n = i;
		printf("%d\n", n);
		while(n < 1000000) {
			// printf(".");
			if(a[n])
				break;
			a[n] = true;
			n += digitsum(n);
		}
		// printf("\n");
	}

}