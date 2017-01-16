#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string recurse(int n, int lvl) {

	// printf("%d : recursing : %d\n", lvl, n);

	int max = 65536;
	int exp = 16;
	string str = "";

	

	while(max != 0 ) {
		if(n/max != 0) {
			if(str.length() == 0) {
				if(exp == 1)
					str = "2";
				else if(exp == 0)
					str = "2(0)";
				else 
					str = "2(" + recurse(exp, lvl+1) + ")";
			}
			else {
				if(exp == 1)
					str = str + "+2";
				else if(exp == 0)
					str = str + "+2(0)";
				else
					str = str + "+2(" + recurse(exp, lvl+1) + ")";
			}
		}
		n = n % max;
		max = max / 2;
		exp--;
	}

	return str;
}

int main() {

	int t,n;
	scanf("%d", &t);

	while(t--) {

		scanf("%d", &n);	
		cout << n << "=" << recurse(n, 1) << "\n";
		
	}
}