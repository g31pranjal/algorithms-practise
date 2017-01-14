#include <iostream>
#include <vector>

using namespace std;

vector<int> mn, ch;

int calc_LCS() {

	vector< vector<int> > a (mn.size() + 1, vector<int> (ch.size() + 1, 0) ); 
	
	for(int i = 1;i<=mn.size();i++) {
		for(int j = 1;j<=ch.size();j++) {
			if(mn[i-1] == ch[j-1])
				a[i][j] = a[i-1][j-1] + 1;
			else 
				a[i][j] = a[i-1][j] > a[i][j-1] ? a[i-1][j] : a[i][j-1];
			// cout << a[i][j] << "\t";
		}
		// cout << "\n";
	}

	return a[mn.size()][ch.size()];

}


int main() {

	int t, tmp, max;
	bool nw;
	cin >> t;

	for(int m=0;m<t;m++) {

		mn.clear();
		max = 0;
		cin >> tmp;
		while(tmp != 0) {
			mn.push_back(tmp);
			cin >> tmp;
		}


		while(true){
			nw = true;
			ch.clear();
			cin >> tmp;
			while(tmp != 0) {
				nw = false;
				ch.push_back(tmp);
				cin >> tmp;		
			}



			if(nw)
				break;
			else{ 
				tmp = calc_LCS();
				if(max < tmp)
					max = tmp;
			}
		}

		cout << max << "\n";



	}

}