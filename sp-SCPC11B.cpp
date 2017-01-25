#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	vector<int> a;
	int stops, tmp, bp;
	bool impossible;

	while(true) {

		a.clear();
		scanf("%d", &stops);
		impossible = false;

		if(stops == 0)
			break;

		for(int i=0;i<stops;i++) {
			scanf("%d", &tmp);
			a.push_back(tmp);
		}

		sort(a.begin(), a.end());


		for(int i=0;i<stops-1;i++) {
			if(a[i+1]-a[i] > 200) {
				impossible = true;
				printf("IMPOSSIBLE\n");
				break;
			}
		}

		if(!impossible) {
			if( 2*(1422 - a[stops-1]) > 200  ) {
				impossible = true;
				printf("IMPOSSIBLE\n");
			}
		}

		if(!impossible)
			printf("POSSIBLE\n");


	}

}
