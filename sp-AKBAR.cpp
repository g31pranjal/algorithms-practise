#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main() {

	int t, n, r, m, t1, t2, b, k;
	scanf("%d", &t);
	vector<bool> prt, vst;
	vector< vector<int> > adj;
	deque< pair<int, int> > q;
	bool opt;
	pair<int, int> ent;

	while(t--) {
		opt = true;
		scanf("%d %d %d", &n, &r, &m);

		prt.clear();
		prt.resize(n, false);
		adj.clear();
		adj.resize( n , vector<int> (0) );

		for(int i=0;i<r;i++) {
			scanf("%d %d", &t1, &t2);
			t1--;
			t2--;
			adj[t1].push_back(t2);
			adj[t2].push_back(t1);
		}

		// ADJACENCY MATRIX 

		// for(int i=0;i<n;i++) {
		// 	printf("%d : ", i);
		// 	for(int j=0;j<adj[i].size();j++) {
		// 		printf("%d -> ", adj[i][j]);
		// 	}
		// 	printf("\n");
		// }

		for(int i=0;i<m;i++) {
			scanf("%d %d", &b, &k);
			
			b--;
			vst.clear();
			vst.resize(n, false);
			q.clear();

			if(prt[b]) {
				opt = false;
				break;
			}

			vst[b] = true;
			q.push_back( make_pair(b,0) );
			prt[b] = true;

			// printf("truing %d\n", b);

			while(!q.empty()) {
				ent = q.front();
				q.pop_front();
				if(ent.second != k) {
					for(int j=0;j<adj[ent.first].size();j++) {
						if(!vst[adj[ent.first][j]]) {
							if(prt[adj[ent.first][j]]) {
								opt = false;
								break;
							}
							vst[adj[ent.first][j]] = true;
							q.push_back(make_pair(adj[ent.first][j], ent.second + 1 ));
							prt[adj[ent.first][j]] = true;
							// printf("truing %d\n", adj[ent.first][j]);
							
						}
					}
					if(!opt)
						break;
				}
			}
			if(!opt)
				break;
		}
		if(opt) {
			for(int i=0;i<n;i++) {
				if(!prt[i])
					opt = false;			
			}
		}
		if(!opt)
			printf("No\n");
		else
			printf("Yes\n");
	}
}