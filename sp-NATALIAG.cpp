#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

int main() {
	int t;
	string str;
	cin >> t;
	vector< vector<char> > a;
	deque< tuple<int, int, int> > bfs;
	tuple<int, int, int> loc;

	for(int m=0;m<t;m++) {
		//cout << "outer loop\n"; 
		int r,c,flag,x,y,z;
		cin >> r >> c;

		a.clear();
		bfs.clear();
		a.resize(r, vector<char> (c,'\0'));
		flag = -1;
		//cout << "t : " << (z) << "\n";

		for(int i=0;i<r;i++) {
			cin >> str;
			for(int j=0;j<c;j++) {
				a[i][j] = str[j];
				if(a[i][j] == '$'){
					bfs.push_back(make_tuple(i, j, 0));
					a[i][j] = '*';
				}
			}
		}

		// for(int i=0;i<r;i++) {
		// 	for(int j=0;j<c;j++) {
		// 		cout << a[i][j] << "\t";
		// 	}
		// 	cout << "\n";
		// }

		// cout << "bfs size : " << bfs.size() << "\n";

		while(!bfs.empty()) {
			loc = bfs.front();
			bfs.pop_front();

			x = get<0>(loc);
			y = get<1>(loc);
			z = get<2>(loc);

			// cout << "in loop : x,y,z" << x << ", " << y << ", " << z << '\n';

			if(x+1 < r) {
				if(a[x+1][y] == 'O') {
					a[x+1][y] = '*';
					bfs.push_back(make_tuple(x+1, y, z+1));
				}
				else if(a[x+1][y] == '#') {
					flag = 1;
					cout << (z+1) << "\n";
					break;
				}
			}

			if(x-1 >=0 ) {
				if(a[x-1][y] == 'O') {
					a[x-1][y] = '*';
					bfs.push_back(make_tuple(x-1, y, z+1));
				}
				else if(a[x-1][y] == '#') {
					flag = 1;
					cout << (z+1) << "\n";
					break;
				}
			}

			if(y+1 < c){
				if(a[x][y+1] == 'O') {
					a[x][y+1] = '*';
					bfs.push_back(make_tuple(x, y+1, z+1));
				}
				else if(a[x][y+1] == '#') {
					flag = 1;
					cout << (z+1) << "\n";
					break;
				}
			}

			if(y-1 >=0) {
				if(a[x][y-1] == 'O') {
					a[x][y-1] = '*';
					bfs.push_back(make_tuple(x, y-1, z+1));
				}
				else if(a[x][y-1] == '#') {
					flag = 1;
					cout << (z+1) << "\n";
					break;
				}
			}

		}

		if(flag == -1)
			cout << "-1\n";



	}
}