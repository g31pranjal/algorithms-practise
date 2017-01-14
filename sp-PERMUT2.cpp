#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, tmp;
	bool na;
	vector<int> a, b;

	while(true) {

		cin >> n;
		if(n == 0)
			break;

		a.clear();
		b.clear();
		a.resize(n, -1);
		b.resize(n, -1);

		for(int i=0;i<n;i++) {
			cin >> tmp;
			a[i] = tmp - 1;
			b[tmp - 1] = i;
		}

		na = false;
		for(int i = 0;i<n;i++) {
			if(a[i] == b[i]);
			else {
				na = true;
				break;
			}
		}

		if(na)
			cout << "not ambiguous\n";
		else
			cout << "ambiguous\n";

	}

}