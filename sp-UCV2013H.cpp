#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int main() {

	int r,c,x,y,p,q, count,num;
	vector< vector<int> > a;
	deque< pair<int,int> > ones;
	deque< pair<int,int> > bfs;
	map<int, int> store;

	while(true) {
		cin >> r >> c;
		if(r == 0 || c == 0) 
			break;
		
		a.clear();
		a.resize(r, vector<int> (c,0) );
		ones.clear();
		store.clear();
		num = 0;

		int probabale = 1;

		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				cin >> a[i][j];
				if(a[i][j] == 1 && probabale == 1){
					ones.push_back(make_pair(i,j));
					probabale = 0;
				}
				else if(a[i][j] == 0) {
					probabale = 1;
				}
			}
			probabale = 1;
		}

		// for(int i=0;i<ones.size();i++) {
		// 	cout << ones[i].first << ", " << ones[i].second << "\n";
		// }

		while(!ones.empty()) {
			x = ones.front().first;
			y = ones.front().second;
			ones.pop_front();
			bfs.clear();


			if(a[x][y] == 1) {
				
				bfs.push_back(make_pair(x,y));
				count = 0;
				a[x][y] = 0;

				//cout << "x, y : " << x << ", " << y << "\n";

				while(!bfs.empty()) {
					p = bfs.front().first;
					q = bfs.front().second;
					bfs.pop_front();
					
					//cout << "p, q : " << p << ", " << q << "\n";

					count++;
					if((p+1 < r) && a[p+1][q] == 1){
						a[p+1][q] = 0;
						bfs.push_back(make_pair(p+1,q));
					}
					if((q+1 < c) && a[p][q+1] == 1){
						a[p][q+1] = 0;
						bfs.push_back(make_pair(p,q+1));
					}
					if((q-1 >=0) && a[p][q-1] == 1){
						a[p][q-1] = 0;
						bfs.push_back(make_pair(p,q-1));
					}
					if((p-1 >=0) && a[p-1][q] == 1){
						a[p-1][q] = 0;
						bfs.push_back(make_pair(p-1,q));
					}
				}

				if(store.find(count) == store.end() )
					store[count] = 1;
				else
					store[count]++;
				
				num++;

			}
		}

		cout << num << "\n";
		for(map<int,int>::iterator i = store.begin(); i != store.end() ; i++) {
			cout << i->first << " " << i->second << "\n";
		} 


	}

}
