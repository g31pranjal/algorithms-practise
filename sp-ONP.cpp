#include <iostream>
#include <deque>

using namespace std;

int main() {

	int t;
	cin >> t;

	for(int z=0;z<t;z++) {

		string str;
		cin >> str;

		deque<char> a;

		for(int i=0;i<str.length();i++) {

			if(str[i] == '(') {
				a.push_front(str[i]);
			}
			else if(str[i] == ')') {
				while(a.front() != '(') {
					cout << a.front();
					a.pop_front();
				}
				a.pop_front();
			}
			else if(str[i] >= 97 && str[i] <= 122){
				cout << str[i];
			}
			else {
				a.push_front(str[i]);
			}

		}

		cout << "\n";

	}

}