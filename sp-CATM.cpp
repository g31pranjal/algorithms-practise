#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int r, c, dm, dc1, dc2, flag;
	cin >> r >> c;

	int t, m[2], c1[2], c2[2];
	cin >> t;

	for(int z=0;z<t;z++) {

		cin >> m[0] >> m[1] >> c1[0] >> c1[1] >> c2[0] >> c2[1];

		flag = 0;

		for(int i=1;i<=r;i+=1) {
			for(int j=1;j<=c;j+=1) {
				if(i == 1 || i == r || j==1 || j==c){
					dm  = abs(i-m[0]) + abs(j-m[1]);
					dc1 = abs(i-c1[0]) + abs(j-c1[1]);
					dc2 = abs(i-c2[0]) + abs(j-c2[1]);

					//cout << dm << ", " << dc1 << ", " << dc2 << "\n";

					if(dm < dc1 && dm < dc2 ){
						flag = 1;
						break;
					}

					//cout << i << ", " << j << "\n";

				}
			}
			if(flag)
				break;
		}

		if(flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

	}
}