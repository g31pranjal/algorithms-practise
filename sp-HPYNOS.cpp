#include <cstdio>
#include <set>

using namespace std;

int dgtsqr(int n) {
	int smsq = 0;
	while(n != 0) {
		smsq += (n%10)*(n%10);
		n /= 10;
	}
	return smsq;
} 

int main() {

	int n;
	set<int> a;
	scanf("%d", &n);
	int i = 0;

	while(n != 1) {
		if(a.find(n) != a.end()){
			printf("-1\n");
			return 0;
		}
		a.insert(n);
		n = dgtsqr(n);
		i++;
	}

	printf("%d\n", i);

}