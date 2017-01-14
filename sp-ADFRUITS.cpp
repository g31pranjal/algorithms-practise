#include <iostream>

using namespace std;

int main() {
	
	string s1, s2;

	while(true) {

		cin >> s1 >> s2;

		//cout << "int : " << s1 << s2 << "\n";

		int m[s1.length() + 1][s2.length() + 1];

		for(int i=0;i<=s1.length();i++) {
			for(int j=0;j<=s2.length();j++) {
				if(i == 0 || j == 0)
					m[i][j] = 0;
				else if(s1[i-1] == s2[j-1])
					m[i][j] = 1 + m[i-1][j-1];
				else 
					m[i][j] = m[i-1][j] > m[i][j-1] ? m[i-1][j] : m[i][j-1];
			}
		}

		
		int s1p=s1.length(), s2p=s2.length();

		string fn = "";

		while(s1p >= 1 || s2p >= 1) {
			if(s1p == 0) {
				fn = s2[s2p - 1] + fn;
				s2p--;
			}
			else if(s2p == 0) {
				fn = s1[s1p - 1] + fn;
				s1p--;
			}
			else {
				if(s1[s1p - 1] == s2[s2p - 1]) {
					fn = s1[s1p - 1] + fn;
					s1p--;
					s2p--;
				}
				else {

					if(m[s1p - 1][s2p] >= m[s1p][s2p-1]) {
						fn = s1[s1p-1] + fn;
						s1p = s1p-1;
						s2p = s2p;
					}
					else {
						fn = s2[s2p-1] + fn;
						s1p = s1p;
						s2p = s2p-1;
					}

				}

			}
		}


		// for(int i=0;i<=s1.length();i++) {
		// 	for(int j=0;j<=s2.length();j++) {
		// 		cout << m[i][j] << "\t";
		// 	}
		// 	cout << "\n";
		// }


		cout << fn << "\n";


		if(cin.eof())
			break;
	}


	// while(getline(cin, s1)) {
	// 	if(s1 == "")
	// 		break;
	// 	else {
	// 		cin >> s2;

	// 	}
	// }
}