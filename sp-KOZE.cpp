#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct {
	bool corner;
	int k;
	int v;
} sector;

int main() {

	int r, c, probable;
	cin >> r >> c;

	vector< vector<char> > a (r , vector<char> (c,'\0') );
	deque<pair<int,int> > canbe, bfs;
	vector<sector> ans;
	pair<int, int> cords;

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			cin >> a[i][j];
		}
	}

	probable = 1;

	for(int i=0;i<r;i++) {
		probable = 1;
		for(int j=0;j<c;j++) {
			// cout <<  a[i][j] << " ";
			if(a[i][j] != '#' && probable == 1) {
				if(i==0 || (i-1 >= 0 && a[i-1][j] == '#' ) ) {
					canbe.push_back(make_pair(i, j));
				}
				probable = 0;
			}
			else if(a[i][j] == '#')
				probable = 1;

		}
		// cout << "\n";
	}

	// for(int i=0;i<canbe.size();i++) {
	// 	cout << canbe[i].first << ", " << canbe[i].second << "\n";
	// }

	while(!canbe.empty()) {
		cords = canbe.front();
		canbe.pop_front();


		if(a[cords.first][cords.second] == '#')
			continue;
		else {
			// cout << "canbe :: \t";
			bfs.clear();

			sector s;
			s.k = 0;
			s.v = 0;
			s.corner = false;

			bfs.push_back(cords);

			if(a[cords.first][cords.second] == 'k')
				s.k++;
			else if(a[cords.first][cords.second] == 'v')
				s.v++;

			a[cords.first][cords.second] = '#';

			while(!bfs.empty()) {

				cords = bfs.front();
				bfs.pop_front();

				//cout << cords.first << ", " << cords.second << "\t";
				
				if(cords.first == 0 || cords.first == r-1 || cords.second == 0 || cords.second == c-1)
					s.corner = true;

				if(cords.first - 1 >= 0 && (a[cords.first-1][cords.second] != '#')) {
					if(a[cords.first - 1][cords.second] == 'k')
						s.k++;
					else if(a[cords.first - 1][cords.second] == 'v')
						s.v++;
					a[cords.first - 1][cords.second] = '#';
					bfs.push_back(make_pair(cords.first - 1, cords.second))	;				
				}
				if(cords.first + 1 < r && (a[cords.first+1][cords.second] != '#')) {
					if(a[cords.first + 1][cords.second] == 'k')
						s.k++;
					else if(a[cords.first + 1][cords.second] == 'v')
						s.v++;
					a[cords.first + 1][cords.second] = '#';
					bfs.push_back(make_pair(cords.first + 1, cords.second));
				}
				if(cords.second - 1 >= 0 && (a[cords.first][cords.second-1] != '#')) {
					if(a[cords.first][cords.second - 1] == 'k')
						s.k++;
					else if(a[cords.first][cords.second - 1] == 'v')
						s.v++;
					a[cords.first][cords.second - 1] = '#';
					bfs.push_back(make_pair(cords.first, cords.second - 1));
				}
				if(cords.second + 1 < c  && (a[cords.first][cords.second+1] != '#')) {
					if(a[cords.first][cords.second + 1] == 'k')
						s.k++;
					else if(a[cords.first][cords.second + 1] == 'v')
						s.v++;
					a[cords.first][cords.second + 1] = '#';
					bfs.push_back(make_pair(cords.first, cords.second + 1))	;				
				}
			}
			// cout << "\nk : " << s.k << "v : " << s.v << "corner : " << s.corner << "\n";
			// cout << "\n";
			ans.push_back(s);
		}
	}

	int k=0, v=0;

	for(int i=0;i<ans.size();i++) {
		//cout << ans[i].k << ", " << ans[i].v << ", " << ans[i].corner << "\n";
		if(ans[i].corner) {
			k += ans[i].k;
			v += ans[i].v;
		} else {
			if(ans[i].k>ans[i].v)
				k += ans[i].k;
			else 
				v += ans[i].v;
		}
	}

	cout << k << " " << v << "\n";
}