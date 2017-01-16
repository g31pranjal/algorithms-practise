#include <cstdio>
#include <unordered_set>

using namespace std;

int main() {

	unordered_set<int> fr, frofr;
	int f, n, tmp, ff;
	scanf("%d", &f);

	for(int i=0;i<f;i++) {

		scanf("%d%d", &tmp, &ff);

		fr.insert(tmp);

		if(frofr.find(tmp) != frofr.end()) {
			frofr.erase(frofr.find(tmp));
		}

		for(int j=0;j<ff;j++) {
			scanf("%d", &tmp);
			if(fr.find(tmp) == fr.end())
				frofr.insert(tmp);
		}
	}

	printf("%d\n", frofr.size());


}