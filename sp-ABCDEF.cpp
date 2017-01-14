#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main() {

	
	int n, lhs, rhs, tmp;
	scanf("%d", &n);

	vector<int> col (n);
	unordered_map<long, unsigned long> l, r;

	//cout << "reading";
	// printf("reading\n");

	for(int i=0;i<n;i++) {
		scanf("%d", &tmp);
		col[i] = tmp;
	}

	// cout << "calc";
	// printf("calc\n");


	for(int a = 0, d = 0 ; a < col.size() && d < col.size() ; a++, d++) {
		for(int b = 0, e = 0 ; b < col.size() && e < col.size() ; b++, e++) {
			for(int c = 0, f = 0 ; c < col.size() && f < col.size() ; c++, f++) {
				lhs = col[a]*col[b] + col[c];
				rhs = col[d]*(col[f] + col[e]);

				if(l.find(lhs) == l.end())
					l[lhs] = 1;
				else
					l[lhs]++;

				if(col[d] != 0) {
					if(r.find(rhs) == r.end())
						r[rhs] = 1;
					else
						r[rhs]++;
				}

			}
		}
	}

	//printf("c done\n");
	// cout << "calc done, match";

	unsigned long count = 0;

	for(unordered_map<long, unsigned long>::iterator it = l.begin(); it != l.end() ;it++) {
		if(r.find(it->first) != r.end())
			count += (it->second*r[it->first]);
	}

	cout << count << "\n";




}