#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

	int t;
	scanf("%d\n", &t);
	string a,p,b,e,s;
	int rec;
	bool isdigit;

	while(t--) {

		cin >> a >> p >> b >> e >> s;

		isdigit = true;

		for(int i=0;i<a.length();i++)
			if(a[i] < 48 || a[i] > 57){
				isdigit = false;
				break;
			}

		if(!isdigit) {
			rec = atoi(s.c_str()) - atoi(b.c_str());
			printf("%d + %s = %s\n", rec, b.c_str(), s.c_str());
			continue;
		}

		for(int i=0;i<b.length();i++)
			if(b[i] < 48 || b[i] > 57){
				isdigit = false;
				break;
			}

		if(!isdigit) {
			rec = atoi(s.c_str()) - atoi(a.c_str());
			printf("%s + %d = %s\n", a.c_str(), rec, s.c_str());
			continue;
		}

		rec = atoi(a.c_str()) + atoi(b.c_str());
		printf("%s + %s = %d\n", a.c_str(), b.c_str(), rec);

	}

}