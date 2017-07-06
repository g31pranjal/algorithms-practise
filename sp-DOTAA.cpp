#include <cstdio>
#include <map>

using namespace std;

int main() {

	int t, n, m, D, tmp, ins_h, left;
	map<int, int> H;
	scanf("%d", &t);

	while(t--) {

		scanf("%d %d %d", &n, &m, &D);
		H.clear();

		for(int i=0;i<n;i++) {
			scanf("%d", &tmp);
			if(H.find(tmp) == H.end())
				H[tmp] = 1;
			else
				H[tmp]++;
		}

		left = n;
		map<int, int>::iterator it;
		for(int i=0;i<m;i++) {
			it = H.end();
			it--;
			ins_h = it->first - D;
			H[it->first]--;
			left--;
			if(H[it->first] == 0)
				H.erase(it->first);
			if(ins_h > 0) {
				if(H.find(ins_h) == H.end())
					H[ins_h] = 1;
				else
					H[ins_h]++;
				left++;
			}
			if(left == 0)
				break;
		}
		if(left == n)
			printf("YES\n");
		else
			printf("NO\n");


	}

}