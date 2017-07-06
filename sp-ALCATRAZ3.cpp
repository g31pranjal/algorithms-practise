#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

vector< vector<char> > a;
vector< vector<bool> > mark;
// deque< tuple<int, int, int> > stk;
tuple<int, int, int> tup;
int n, m, k, startx, starty;


bool dfs_call(int x, int y, int step) {
	// cout << "x : " << x << " y : " << y << " step : " << step << "\n";

	if(x-1 >= 0 && a[x-1][y] == '.') {
		if(x-1 == startx && y == starty) {
			if(step+1 >= k)
				return true;
		}
		else if(!mark[x-1][y]) {
			mark[x-1][y] = true;
			if(dfs_call(x-1, y, step+1) )
				return true;
			mark[x-1][y] = false;
		}
	}
	if(x+1 < n && a[x+1][y] == '.') {
		if(x+1 == startx && y == starty) {
			if(step+1 >= k)
				return true;
		}
		else if(!mark[x+1][y]) {
			mark[x+1][y] = true;
			if(dfs_call(x+1, y, step+1) )
				return true;
			mark[x+1][y] = false;
		}
	}
	if(y-1 >= 0 && a[x][y-1] == '.') {
		if(x == startx && y-1 == starty) {
			if(step+1 >= k)
				return true;
		}
		else if(!mark[x][y-1]) {
			mark[x][y-1] = true;
			if(dfs_call(x, y-1, step+1) )
				return true;
			mark[x][y-1] = false;
		}
	}
	if(y+1 < m && a[x][y+1] == '.') {
		if(x == startx && y+1 == starty) {
			if(step+1 >= k)
				return true;
		}
		else if(!mark[x][y+1]) {
			mark[x][y+1] = true;
			if(dfs_call(x, y+1, step+1) )
				return true;
			mark[x][y+1] = false;
		}
	}
	return false;
}


int main() {

	scanf("%d %d\n%d\n%d %d\n", &n, &m, &k, &startx, &starty);
	char tmp;

	a.resize(n, vector<char> ( m, '\0') ) ;
	mark.resize(n, vector<bool> ( m, false) ) ;
	// stk.clear();
	startx--;
	starty--;

	// stk.push_back(make_tuple(x-1, y-1, 0));

	mark[startx][starty] = true;
	

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%c ", &tmp);
			a[i][j] = tmp;
		}
	}

	if(dfs_call(startx, starty, 0) )
		cout << "YES";
	else
		cout << "NO";



}