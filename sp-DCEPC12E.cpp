#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

	int dim, tmp, q, pi, pj, val, old;
	char mtx;
	scanf("%d", &dim);
	unsigned long long sum = 0;

	int a[dim][dim], b[dim][dim];
	vector<unsigned long long> a_cols (dim,0), b_rows (dim,0);

	for(int i=0;i<dim;i++) {
		for(int j=0;j<dim;j++) {
			scanf("%d", &tmp);
			a[i][j] = tmp;
			a_cols[j] += tmp;
		}
	}

	for(int i=0;i<dim;i++) {
		for(int j=0;j<dim;j++) {
			scanf("%d", &tmp);
			b[i][j] = tmp;
			b_rows[i] += tmp;
			sum += b[i][j] * a_cols[i];
		}
	}

	scanf("%d", &q);

	for(int i=0;i<q;i++) {
		cin >> mtx >> pi >> pj >> val;
		//printf("%c %d %d %d \n", mtx, pi, pj, val);
		if(mtx == 'A') {
			old = a[pi][pj];
			sum = sum - old*b_rows[pj] + val*b_rows[pj];
			a_cols[pj] = a_cols[pj] - old + val;
			a[pi][pj] = val;
		}
		else if(mtx == 'B') {
			old = b[pi][pj];
			sum = sum - old*a_cols[pi] + val*a_cols[pi];
			b_rows[pi] = b_rows[pi] - old + val;
			b[pi][pj] = val;
		}
		printf("%lld\n", sum);

	}

}