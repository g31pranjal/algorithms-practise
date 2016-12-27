#include <iostream>

using namespace std;

int main() {

	int t;

	cin >> t;

	for(int z=0;z<t;z++) {

		int x, y, num, sl;

		cin >> x >> y;

		if(x == 0 && y == 0)
			cout << "0\n";
		else if(x == 1 && y == 1)
			cout << "1\n";
		else {
			sl = x/2 - 1;

			num = sl*4 + 2;

			if(x%2 == 1)
				num++;

			if(x == y)
				cout << num+2 << "\n";
			else if(y == x-2)
				cout << num << "\n";
			else 
				cout << "No Number\n";



		}


	}

}