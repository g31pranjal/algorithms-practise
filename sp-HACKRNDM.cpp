#include <iostream>
#include <map>

using namespace std;

int main() {

	int n, k, tp;
	long long int num = 0;
	cin >> n >> k;
	map<int, int> a;

	for(int i=0;i<n;i++) {
		cin >> tp;
		if(a.find(tp) == a.end()) 
			a[tp] = 1;
		else
			a[tp]++;
	} 

	for(map<int, int>::iterator i=a.begin(); i != a.end(); i++) {
		if(a.find(i->first + k) != a.end())
			num += i->second * a[i->first + k];
	} 


	cout << num << "\n";

}