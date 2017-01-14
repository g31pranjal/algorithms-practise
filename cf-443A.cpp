#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	string s;
	getline(cin, s);
	map<char, int> a;

	for(int i=0;i<s.length();i++) {
		// cout << s[i] << "\n";
		if(s[i] == '}' || s[i] == '{' || s[i] == ' ' || s[i] == ',')
			continue;
		else if(a.find(s[i]) == a.end()){
			// cout << "else\n";
			a[s[i]] = 1;
		}
	}
	cout << a.size() << "\n";
}