#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


vector<int> sg_tree, a;

void build_sg(int index, int l, int r) {
	if(l == r) {
		sg_tree[index] = a[r];
	}
	else {
		int mid = (r + l) / 2;
		build_sg(2*index + 1, l, mid);
		build_sg(2*index + 2, mid + 1, r);
		sg_tree[index] = sg_tree[2*index + 1] & sg_tree[2*index + 2];
	}
}

int query_sg(int index, int l, int r, int ql, int qr) {
	if(ql > r || qr < l)
		return -1;
	else if(ql <= l && qr >= r) 
		return sg_tree[index];
	else {
		int mid = (r + l)/2;
		return query_sg(2*index + 1, l, mid, ql, qr) & query_sg(2*index + 2, mid + 1, r, ql, qr);
	}
}

void print_sg() {
	for(int i=0;i<sg_tree.size();i++)
		cout << sg_tree[i] << "\t";
	cout << "\n";
}

int main() {

	int t, n, k, nn, pow, tmp, ub, lb;
	scanf("%d", &t);

	for(int m=0;m<t;m++) {

		scanf("%d%d",&n, &k);
		nn = n;
		pow = 2;

		while(nn != 0) {
			pow *= 2;
			nn = nn/2;
		}
		
		a.clear();
		a.resize(n,0);
		sg_tree.clear();
		sg_tree.resize(pow,0);

		for(int i=0;i<n;i++) {
			scanf("%d", &tmp);
			a[i] = tmp;
		}

		build_sg(0, 0, n-1);

		for(int i=0;i<n;i++) {
			if(2*k + 1 >= n){
				// cout << "over bound";
				a[i] = query_sg(0, 0, n-1, 0, n-1);
			}
			else {
				lb = (i-k + n)%n;
				ub = (i+k)%n;
				if(lb <= ub){
					// cout << "one query ";
					a[i] = query_sg(0, 0, n-1, lb, ub);
				}
				else {
					// cout << "two query ";
					a[i] = query_sg(0, 0, n-1, 0, ub) & query_sg(0, 0, n-1, lb, n-1);
				}
			}
		}

		for(int i=0;i<n;i++) {
			cout << a[i] << " ";
		}
		cout << "\n";


	}


}