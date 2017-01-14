#include <iostream>

using namespace std;

int main() {

	string str;
	int global = 1;


	while(true) {
		cin >> str;

		if(str[0] == '-')
			break;
		else {
			int c = 0;
			int ans = 0;

			for(int i=0;i<str.length();i++) {
				if(str[i] == '}') {
					if(c > 0)
						c--;
					else if(c == 0) {
						ans++;
						c++;
					}
				}
				else if(str[i] == '{') {
					c++;
				}
			}

			ans += (c/2);
			
			cout << global << ". " << ans << "\n";
			global++;


		}


	}

}