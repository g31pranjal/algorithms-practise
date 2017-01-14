#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	int t, flag;
	cin >> t;
	vector< vector<char> > a;
	deque< pair<int,int> > bfs;
	pair<int,int> goal, t1;

	for(int m=0;m<t;m++) {
		
		int r, c;
		cin >> r >> c;
		a.clear();
		a.resize(r, vector<char> (c,'\0') );
		bfs.clear();

		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				cin >> a[i][j];
				if( (i==0 || j==0 || i == r-1 || j == c-1) && (a[i][j] == '.') ) {
					bfs.push_back(make_pair(i,j));
				} 
			}
		}

		if(bfs.size() != 2) {
			cout << "invalid" << "\n";
		}
		else {
			goal = bfs.front();
			bfs.pop_front();
			flag = 0;
			a[bfs.front().first][bfs.front().second] = '#';

			while(!bfs.empty()) {
				t1 = bfs.front();
				bfs.pop_front();

				if( (t1.first - 1) >= 0 && a[t1.first - 1][t1.second] == '.') {
					if(t1.first - 1 == goal.first && t1.second == goal.second ){
						cout << "valid\n";
						flag = 1;
						break;
					}
					a[t1.first - 1][t1.second] = '#';
					bfs.push_back(make_pair(t1.first - 1, t1.second));
				}

				if( (t1.first + 1) <  r && a[t1.first + 1][t1.second] == '.') {
					if(t1.first + 1 == goal.first && t1.second == goal.second ){
						flag = 1;
						cout << "valid\n";
						break;
					}	
					a[t1.first + 1][t1.second] = '#';
					bfs.push_back(make_pair(t1.first + 1, t1.second));
				}

				if( (t1.second - 1) >= 0 && a[t1.first][t1.second - 1] == '.') {
					if(t1.first == goal.first && t1.second - 1 == goal.second ){
						flag = 1;
						cout << "valid\n";
						break;
					}
					a[t1.first][t1.second - 1] = '#';
					bfs.push_back(make_pair(t1.first, t1.second - 1));
				}

				if( (t1.second + 1) < c && a[t1.first][t1.second + 1] == '.') {
					if(t1.first == goal.first && t1.second + 1 == goal.second ){
						flag = 1;
						cout << "valid\n";
						break;
					}
					a[t1.first][t1.second + 1] = '#';
					bfs.push_back(make_pair(t1.first, t1.second + 1));
				}
			}

			if(flag == 0) 
				cout << "invalid\n";

		}





	}
}