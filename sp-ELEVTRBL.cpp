#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {

	int f, s, g, u, d, curr;

	cin >> f >> s >> g >> u >> d;



	if(s == g)
		cout << "0\n";
	else {
		vector<int> fl (f+1, -1);
		deque<int> bfs;
		fl[s] = 0;

		bfs.push_back(s);

		while(!bfs.empty()) {
			curr = bfs.front();
			bfs.pop_front();

			//cout << "popped : " << curr << "\n";

			// for (int m=0;m<fl.size();m++)
			// 	cout << fl[m] << "\t";
			// cout << "\n";

			if(curr + u <= f && fl[curr + u] == -1) { 
				fl[curr + u] = fl[curr] + 1;
				if(curr + u == g){
					cout << fl[curr] + 1 << "\n";
					break;
				}
				else
					bfs.push_back(curr + u);
			}
			
			if(curr - d >= 1 && fl[curr - d] == -1) {
				fl[curr - d] = fl[curr] + 1;
				if(curr - d == g) {
					cout << fl[curr] + 1 << "\n";
					break;
				}
				else
					bfs.push_back(curr - d);
			}
		}

		if(fl[g] == -1)
			cout << "use the stairs" << "\n";


	}


}