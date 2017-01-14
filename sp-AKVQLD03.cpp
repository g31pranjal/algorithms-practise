#include <iostream>
#include <vector>

using namespace std;

vector<int> a ;

void print() {
	for(int i=0;i<a.size();i++) 
		cout << a[i] << "\t";
	cout << "\n";
}

void update(int index, int rangeL, int rangeR, int loc, int val) {

	int mid;

	if(loc < rangeL || loc > rangeR) {
	}
	else if(rangeL == rangeR) {
		a[index] += val;
	}
	else {
		mid = (rangeL + rangeR)/2;
		update(2*index + 1, rangeL, mid, loc, val);
		update(2*index + 2, mid + 1, rangeR, loc, val);
		a[index] = a[2*index + 1] + a[2*index + 2];
	}
}

int query(int index, int rangeL, int rangeR, int qrL, int qrR) {
	if(qrR < rangeL || qrL > rangeR)
		return 0;
	else if(qrL <= rangeL && qrR >= rangeR)
		return a[index];
	else {
		int mid = (rangeL + rangeR) /2;
		return query(2*index + 1, rangeL, mid, qrL, qrR) + query(2*index + 2, mid+1, rangeR, qrL, qrR);
	}
}

int main() {

	int n, q, t1, t2;
	string cmd;
	cin >> n >> q;

	int pow = 2;
	int nn = n;

	while(nn != 0) {
		pow *= 2;
		nn /= 2;
	}

	// initialiizing the segment tree
	a.resize(pow, 0);

	//update(0, 0, n-1, 6, 5);

	for(int i=0;i<q;i++) {
		cin >> cmd >> t1 >> t2;
		if(cmd[0] == 'f') {
			// find the range summation
			cout << query(0, 0, n-1, t1-1, t2-1) << "\n";
		}
		else if(cmd[0] == 'a') {
			update(0, 0, n-1, t1-1, t2);
			// print();
		}

	}


}