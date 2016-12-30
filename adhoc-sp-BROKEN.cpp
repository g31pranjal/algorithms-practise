#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main () {

	int n, max, keys;
	string str;
	char chr;
	vector<int> map;
	deque<int> set;

	while(true) {
		getline(cin, str);
		n = stoi(str);
		if(n == 0)
			break;

		str = "";
		getline(cin,  str);
		map.clear();
		map.resize(128, 0);
		set.clear();

		max = 0;
		keys = 0;

		for(int i=0;i<str.size();i++) {
			chr = str[i];
			// cout << "dealing " << chr << "\n";
			if(map[(int)chr] != 0) {
				// cout << "in map. no action required\n";
			}
			else {
				if(keys < n) {
					keys++;
					// cout << "not in map. key increased to " << keys << "\n";
				}
				else {
					// cout << "keys full\n";
					// cout << "set.front : " << set.front() << ", map set.front : " << map[set.front()] << "\n";
					while(map[set.front()] - 1 != 0) {
						map[set.front()]--;
						set.pop_front();
					}
					map[set.front()] = 0;
					set.pop_front();
				}

			}
			map[(int)chr]++;
			set.push_back((int)chr);
			if(set.size() > max)
				max = set.size();

			// for(int j=0;j<set.size();j++)
			// 	cout << "'" << (char)set[j] << "' ";
			// cout << "\n"; 
		
		}

		cout << max << "\n";
	}
}