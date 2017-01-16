#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {

	int n, k, s, f;

	scanf("%d%d", &n, &k);

	vector<set<int> > a (6);

	int moves = 0;

	for(int i=0;i<n;i++) {
		
		scanf("%d%d", &s, &f);
		s--;
		
		if(a[s].begin() == a[s].end() ) {
			// printf("empty\n");
			moves++;
			a[s].insert(f);
		}	
		else {
			if(f < *(a[s].begin())) {
				// printf("smallest\n");
				moves += a[s].size();
				a[s].clear();
				a[s].insert(f);
				moves++;
			}
			else if( f > *(--a[s].end())) {
				// printf("end : %d\n", *(--a[s].end()));
				// printf("bigger\n");
				moves++;
				a[s].insert(f);
			}
			else {
				if(a[s].find(f) == a[s].end()) {
					a[s].insert(f);
					moves++;
				}
				// printf("point : %d\n", *a[s].find(f));
				
				while(  a[s].begin() != a[s].end()  &&  f <  *(--a[s].end())  ) {
					a[s].erase(--a[s].end());
					moves++;
				}


			}
		}

		// printf("%d : ", s);

		// for(set<int>::iterator p=a[s].begin();p!= a[s].end();p++) 
		// 	printf("%d\t", *p);
		// printf("\n");

		// printf("moves :: %d\n", moves);

		// printf("\n");

	}

	printf("%d\n", moves);
}