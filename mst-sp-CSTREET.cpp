#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> a;

bool edge_sort(pair<pair<int, int>, int  > a, pair<pair<int, int>, int  > b) {
	return a.second < b.second;
}

void ds_init() {
	for(int i=0;i<a.size();i++) {
		a[i] = i;
	}
}

int ds_root(int index) {
	while(index != a[index]){
		index = a[index];	
	}
	return index;
}

void ds_merge(int i1, int i2) {
	a[ds_root(i1)] = ds_root(i2);
}

int main() {

	unsigned int t, p, n, m, t1, t2, t3, i1, i2;
	deque<pair<pair<int, int>, int  > > edges;
	pair<pair<int, int>, int  > loc;
	cin >> t;

	for(int z=0;z<t;z++) {
		cin >> p >> n >> m;

		a.clear();
		a.resize(n, -1);
		ds_init();

		edges.clear();

		for(int i=0;i<m;i++) {
			cin >> t1 >> t2 >> t3;
			edges.push_back(make_pair(make_pair(t1-1, t2-1), t3));
		}

		sort(edges.begin(), edges.end(), edge_sort);

		// for(int i=0;i<m;i++) {
		// 	printf("%d,%d : %d\n", edges[i].first.first, edges[i].first.second, edges[i].second);
		// }

		unsigned int sum = 0;

		while(!edges.empty()) {

			loc = edges.front();
			edges.pop_front();

			i1 = loc.first.first;
			i2 = loc.first.second;

			if(ds_root(i1) != ds_root(i2)) {
				sum += loc.second;
				ds_merge(i1, i2);
			}

		}	

		cout << p*sum << "\n";


	}



}
