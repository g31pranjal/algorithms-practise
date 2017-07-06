#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {

	string str;
	string ans;
	int unit, cov, k;

	while(true) {
		getline(cin, str);

		ans = "";

		if(str.length() == 1 && str[0] == '1' )
			cout << str[0] << "\n";
		else {
			cov = 0;
			for(int i = str.length() - 1;i>=0;i--) {
				unit = ((int)str[i] - 48)*2 + cov;
				ans = (char)(unit%10 + 48) + ans; 
				cov = (unit/10)%10;
			}
			if(cov != 0)
				ans = (char)(cov + 48) + ans; 

			// cout << ans << "\n";

			if(ans[ans.length() - 1	] >= '2')
				ans[ans.length() - 1] -= 2;
			else {
				ans[ans.length() - 1] = (10 + (ans[ans.length() - 1] - 48) - 2) + 48;
				k = ans.length()-2;
				while(ans[k] == '0') {
					ans[k] = '9';
					k--;
				}
				ans[k]--;
			}
			if(ans[0] == '0')
				cout << ans.substr(1) << "\n";
			else
				cout << ans << "\n";

		}

		if(cin.eof())
			break;

	}

}