#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> a;

void ds_init() {
	for(int i=0;i<a.size();i++) {
		a[i] = i;
	}
}

int ds_root(int index) {
	while(index != a[index]){
		index = a[index];
		a[index] = a[a[index]];
	}
	return index;
}

void ds_merge(int i1, int i2) {
	a[ds_root(i1)] = ds_root(i2);
}

int edge_sort(pair<  pair<int, int> , int > a, pair<  pair<int, int> , int >  b) {
	return a.second < b.second;
}

int main() {

	unsigned int t, n, t1, t2, nn, root_a, root_b;
	string cname;
	cin >> t;
	deque<pair<  pair<int, int> , int > > edges;
	pair<  pair<int, int> , int > loc;

	for(int m=0;m<t;m++) {

		cin >> n;
		a.clear();
		edges.clear();

		a.resize(n, -1);
		ds_init();

		// cout << "value of N : " << n << "\n";

		for(int i=0;i<n;i++) {
			cin >> cname;
			cin >> nn;
			for(int j=0;j<nn;j++) {
				cin >> t1 >> t2;
				edges.push_back(make_pair(make_pair(i,t1-1) , t2 ));
			}
		}

		sort(edges.begin(), edges.end(), edge_sort);

		// for(int i=0;i<edges.size();i++) {
		// 	printf("%d, %d : %d\n", edges[i].first.first, edges[i].first.second, edges[i].second);
		// }

		unsigned int sum = 0;

		while(!edges.empty()) {

			loc = edges.front();
			edges.pop_front();

			// printf("considering : %d, %d : %d\n", loc.first.first, loc.first.second, loc.second);
	
			// for(int i=0;i<n;i++) {
			// 	cout << i << "," << a[i] << "\t";
			// }
			// cout << "\n";
	
			root_a = ds_root(loc.first.first);
			root_b = ds_root(loc.first.second);
			// printf("root of %d is %d\n", loc.first.first , root_a);
			// printf("root of %d is %d\n", loc.first.second, root_b);

			if(root_a !=root_b) {
				sum += loc.second;
				ds_merge(loc.first.first, loc.first.second);
			}
		}




		cout << sum << "\n";
	}

}