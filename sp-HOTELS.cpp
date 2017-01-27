#include <cstdio>
#include <deque>

using namespace std;

int main() {

	int n, m, tmp, tmp1;
	scanf("%d %d", &n, &m);

	deque<int> a;
	int window = 0, global = 0;

	for(int i=0;i<n;i++) {
		scanf("%d", &tmp);
		while(!a.empty() && tmp+window > m) {
			tmp1 = a.front();
			a.pop_front();
			window -= tmp1;
		}
		a.push_back(tmp);
		window += tmp;
		if(window > global)
			global = window;
	}

	printf("%d\n", global);	


}