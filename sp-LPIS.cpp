#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {

	int n, t;
	cin >> n;

	map<int,int> a;
	int max = 0;

	for(int i=0;i<n;i++) {
		cin >> t;
		if(a.find(t-1) != a.end()) {
			if(a[t-1] + 1 > a[t]) 
				a[t] = a[t-1] + 1;
		}
		else {
			a[t] = 1;
		}
		if(a[t] > max)
			max = a[t];

		// for(map<int, int>::iterator j = a.begin();j!=a.end();j++)
		// 	printf("%d -> %d\t", j->first, j->second);
		// printf("\n");

	}

	printf("%d\n", max);




}