#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool by_r( pair< pair<int, int> , int> a, pair< pair<int, int> , int> b ) {
	return a.first.first > b.first.first;
}

bool by_R( pair< pair<int, int> , int> a, pair< pair<int, int> , int> b ) {
	return a.first.second > b.first.second;
}

int main() {

	int t, n, r, R;
	vector< pair< pair<int, int> , int> > a;
	scanf("%d", &t);

	while(t--) {

		scanf("%d", &n);

		a.clear();

		for(int i=0;i<n;i++) {
			scanf("%d %d ", &r, &R);
			a.push_back(make_pair( make_pair(r,R) , i+1));
		}

		sort(a.begin(), a.end(), by_r);

		int inner = a[0].first.first;

		vector< pair< pair<int, int> , int> >::iterator it = a.begin();
		it++;

		sort(it, a.end(), by_R);

		int outer = a[1].first.second;

		if(outer < inner) 
			printf("%d\n", a[0].second);
		else
			printf("-1\n");

	}


}