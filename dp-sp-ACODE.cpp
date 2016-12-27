#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	string str;
	int nm;

	do {
		cin >> str;
		if(str[0] == '0')
			break;

		vector<long> cumm (str.length() + 1,0);

		cumm[0] = 1; 

		for(int i=0;i < str.length();i++) {
			if(i==0)
				cumm[i+1] = 1;
			else {
				if(str[i] != '0')
					cumm[i+1] = cumm[i];
				if(i >= 1) {
					nm = ((int)str[i-1] - 48)*10 + ((int)str[i] - 48);
					//cout << "num : " << nm << "\n";
					if(nm <= 26 && nm >= 10) {
						cumm[i+1] += cumm[i-1];
					}
				}
			}
		}

		// for(int i=0;i<=str.length();i++) {
		// 	cout << cumm[i] << "\t";
		// }
		// cout << "\n";

		cout << cumm[str.length()] << "\n";



	}while(true);
}