#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {

	vector<int> lst;
	set<int> a;
	int num, prev;

	a.insert(0);
	lst.push_back(0);

	while(true) {

		scanf("%d", &num);

		if(num == -1)
			break;

		for(int i=lst.size();i<=num;i++) {
			prev = lst[i-1];
			if(a.find(prev-i) == a.end() && prev-i > 0) {
				lst.push_back(prev-i);
				a.insert(prev-i);
			}
			else {
				lst.push_back(prev+i);
				a.insert(prev+i);
			}
		}

		printf("%d\n", lst[num]);

	}


}