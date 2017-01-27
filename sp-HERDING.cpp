#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int r, c;
vector< vector<char> > a;
vector< vector < pair<int, int> > > sts;

int sts_init() {
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			sts[i][j] = make_pair(i,j);
		}
	}
}

pair<int, int> head(int x, int y) {
	pair<int, int> ent;
	while(x != sts[x][y].first || y != sts[x][y].second ) {
		ent = sts[x][y];
		x = ent.first;
		y = ent.second;
	}
	return make_pair(x, y);
}

int change(int sx, int sy, int dx, int dy) {
	pair<int, int> dh;
	if( dx<r && dy<c && dx >=0 && dy >= 0 ) {
		dh = head(dx, dy);
		sts[sx][sy] = dh;
	}
}

int main() {

	scanf("%d %d\n", &r, &c);
	a.resize( r, vector<char> (c,'\0') );
	sts.resize( r, vector< pair<int, int> > (c, make_pair(0,0) ) );
	sts_init();
	string tmp;
	set<int> num;
	pair<int, int> ent;

	for(int i=0;i<r;i++) {
		getline(cin, tmp);
		for(int j=0;j<c;j++) {
			a[i][j] = tmp[j];
		}
	}

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			// printf("processing %d, %d\n", i, j);
			switch(a[i][j]) {
				case 'S' :
					change(i, j, i+1, j);
					break;
				case 'N' :
					change(i, j, i-1, j);
					break;
				case 'W' :
					change(i, j, i, j-1);
					break;
				case 'E' :
					change(i, j, i, j+1);
					break;
			}
		}
	}

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			ent = head(i,j);
			num.insert( c*ent.first + ent.second );
		}
	}

	// for(int i=0;i<r;i++) {
	// 	for(int j=0;j<c;j++) {
	// 		printf("%d,%d\t", head(i,j).first, head(i,j).second );
	// 	}
	// 	printf("\n");
	// }

	printf("%d\n", num.size());


}