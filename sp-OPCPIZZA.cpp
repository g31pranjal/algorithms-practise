#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int t, n, m, tmp;
	vector<int> a;
	scanf("%d", &t);

	for(int z =0;z<t;z++) {
		
		scanf("%d%d", &n, &m);
		a.clear();

		for(int i=0;i<n;i++) {
			scanf("%d", &tmp);
			a.push_back(tmp);
		}

		sort(a.rbegin(), a.rend());

		int j = a.size() - 1;
		int i = 0, cnt = 0;

		// for(int i=0;i<n;i++) {
		// 	cout << a[i] << "\t";
		// }
		// cout << "\n";

		while(i<j) {
			if(a[i] + a[j] == m){
				cnt++;
				i++;
				j--;
			}
			else {
				if(m > a[i]+a[j])
					j--;
				else 
					i++;
			}
		}
		
		printf("%d\n", cnt);

	}

}