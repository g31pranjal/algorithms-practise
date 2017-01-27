#include <cstdio>
#include <map>
#include <deque>

using namespace std;

int main() {

	int n, k, out, tmp, inp[1000000];
	scanf("%d", &n);

	map<int,int> a;
	deque<int> wnd;
	map<int,int>::iterator it;

	for(int i=0;i<n;i++) {
		scanf("%d", &inp[i]);
	}

	scanf("%d", &k);
	
	for(int i=0;i<n;i++) {

		wnd.push_back(inp[i]);

		if(a.find(inp[i]) == a.end())
			a[inp[i]] = 1;
		else
			a[inp[i]]++;
		
		if(wnd.size() > k) {
			out = wnd.front();
			wnd.pop_front();
			// printf("a out %d\n", a[out] );
			a[out]--;
			
			if(a[out] == 0)
				a.erase(a.find(out));
		}


		if(i >= k-1) {
			it = a.end();
			it--;
			printf("%d ", it->first);
		}

	
	}


}