#include <vector>
#include <iostream>

using namespace std;

int main() {
	long long a,b,c,d,s;

	cin >> a >> b >> c;

	s = 2;

	while(s != c) {
		
		d = b*b + a;
		a = b;
		b = d;
		s++;
	
	}

	cout << d ;

	return d ;

}