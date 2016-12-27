#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int m=0;m<t;m++) {
		string s;
		cin >> s;
		int nok = 0, ccnt = 0, fn = 0;
		for(int i=0;i<s.length();i++) {
			if(s[i] == 'K') {
				nok++;
				fn = fn+= ccnt;
			}
			else if(s[i] == 'E') 
				ccnt += nok;
		}
		cout << fn << "\n";
	}
}				