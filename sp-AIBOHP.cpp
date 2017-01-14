// minimum number of characters to add to make the string ('f', 't') palindromes

# include <iostream>

using namespace std;

int count[6000][6000];

int main() {

	int t, len;

	cin >> t;

	for(int m=0;m<t;m++) {
		string str;
		cin >> str;

		len = str.length();

		for(int i=0;i<=len;i++) {
			for(int j=0;j<=len;j++) {

				if(i==0 || j==0){
					count[i][j] = 0;
				}
				else if(str[i-1] == str[len - j]){
					count[i][j] = count[i-1][j-1] + 1;
				}
				else{
					count[i][j] = count[i][j-1] > count[i-1][j] ? count[i][j-1] : count[i-1][j];
				}
			}
		}

		// for(int i=0;i<=len;i++) {
		// 	for(int j=0;j<=len;j++) {
		// 		cout << count[i][j] << "\t";
		// 	}
		// 	cout << "\n";
		// }

		cout <<  len - count[len][len] << "\n";		


	}

}