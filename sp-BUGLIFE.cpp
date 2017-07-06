#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>

using namespace std;

int main() {

	int tc, v, e, h, t;
	int * adj, * vrt;
	bool ambig;
	deque<int> stk;

	scanf("%d\n", &tc);

	for(int p=1;p<=tc;p++) {
		scanf("%d %d\n", &v, &e);
		
		adj = (int *)malloc(v*v*sizeof(int));
		vrt = (int *)malloc(v*sizeof(int));
		memset(adj, 0, v*v*sizeof(int));
		memset(vrt, 0, v*sizeof(int));

		for(int i=0;i<e;i++) {
			scanf("%d %d\n", &h, &t);
			h--;
			t--;
			adj[h*v + t] = adj[t*v + h] = 1;
		}

		// for(int i=0;i<v;i++) {
		// 	for(int j=0;j<v;j++) {
		// 		printf("%d ", adj[i*v + j]);
		// 	}
		// 	printf("\n");
		// }

		stk.clear();
		ambig = false;

		for(int f=0;f<v;f++) {
			if(vrt[f] == 0) {
				// printf("----------------------------------\n");
				vrt[f] = 1;
				stk.push_back(f);

				while(!stk.empty()) {
					// printf("popping %d having color %d\n", stk.front(), vrt[stk.front()]);
					for(int i=0;i<v;i++) {
						if(adj[stk.front()*v + i] == 1) {
							if(vrt[stk.front()] == 1) {
								if(vrt[i] == 0) {
									vrt[i] = 2;
									stk.push_back(i);
									// printf("pushing %d\n", i);
								}
								else if(vrt[i] == 1) {
									ambig = true;
									break;
								}
							}
							else if(vrt[stk.front() == 2]){
								if(vrt[i] == 0) {
									vrt[i] = 1;
									stk.push_back(i);
									// printf("pushing %d\n", i);
								}
								else if(vrt[i] == 2) {
									ambig = true;
									break;
								}
							}
						}
					}
					if(ambig)
						break;
					stk.pop_front();
				}
				if(ambig)
					break;
			}
		}



		printf("Scenario #%d:\n", p);

		if(ambig)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");

		free(adj);
		free(vrt);


	}

	return 0;

}