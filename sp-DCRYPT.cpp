#include <iostream>
#include <string>

using namespace std;

int main() {

	int t, key;
	bool change;
	string str;
	cin >> t;

	while(t--) {
		cin >> key;
		cin >> str;
		
		change = false;

		if(key >= 26 && key <= 51) {
			change = true;
			key -= 26;
		}

		for(int i=0;i<str.length();i++) {
			if(str[i] == '.')
				str[i] = ' ';
			else {
				if(str[i] >= 65 && str[i] <= 90 ) {
					str[i] = (  (  (str[i] - 65) + key  )  %  26  )  +  65;
					if(change)
						str[i] += 32;
				}
				else if(str[i] >= 97 && str[i] <= 122 ) {
					str[i] = (  (  (str[i] - 97) + key  )  %  26  )  +  97;
					if(change)
						str[i] -= 32;
				}
			}
		}

		cout << str << "\n";



	}


}