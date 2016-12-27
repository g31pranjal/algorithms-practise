#include <iostream>

using namespace std;

int main() {
	int n, p, maxturns, turns, ans;

	cin >> n >> p;

	maxturns = n/2;
	turns = p/2;

	ans = (turns < (maxturns - turns)) ? turns : maxturns-turns ;

	cout << ans << "\n";

}