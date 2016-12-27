#include <vector>
#include <iostream>
#include <string>


using namespace std;

vector<unsigned long long> mat (1,0);

unsigned long long recurring(int num) {

	int p1, p2, p3;
	unsigned long long b1, b2, b3;
	p1 = num/2;
	p2 = num/3;
	p3 = num/4;

	if(p1 < 100000)
		b1 = mat[p1];
	else 
		b1 = recurring(p1);

	if(p2 < 100000)
		b2 = mat[p2];
	else 
		b2 = recurring(p2);

	if(p3 < 100000)
		b3 = mat[p3];
	else 
		b3 = recurring(p3);	

	return b1 + b2 + b3;
}

int main() {
	string a;
	int num,p1,p2,p3;
	unsigned long long broke;
	
	while(getline(cin, a)) {
		if(a == "")
			break;
		else {
			num = stoi(a);
			while( mat.size() <= num && mat.size() < 100000) {
				p1 = mat.size()/2;
				p2 = mat.size()/3;
				p3 = mat.size()/4;

				broke = mat[p1] + mat[p2] + mat[p3];

				if(broke > mat.size()) 
					mat.push_back(broke);
				else
					mat.push_back(mat.size());
			}

			if(mat.size() <= num) {
				cout << recurring(num) << "\n";
			}
			else 
				cout << mat[num] << "\n";
		}
	}

	return 0;


}