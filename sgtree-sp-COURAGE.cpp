#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> a;
vector< pair<unsigned long long, unsigned long long> > sg_tree;

void print() {
	for(int i=0;i<sg_tree.size();i++) 
		cout << sg_tree[i].first << "," << sg_tree[i].second << "  ";
	cout << "\n";
}

void build_sg(int index, int rngL, int rngR) {
	if(rngR == rngL)
		sg_tree[index] = make_pair(a[rngL], a[rngL]);
	else {
		int mid = (rngL + rngR)/2;
		build_sg(2*index + 1, rngL, mid);
		build_sg(2*index + 2, mid + 1, rngR);
		sg_tree[index] = make_pair( sg_tree[2*index + 1].first + sg_tree[2*index + 2].first , sg_tree[2*index + 1].second > sg_tree[2*index + 2].second ? sg_tree[2*index + 2].second : sg_tree[2*index + 1].second );
	}
}

pair<unsigned long long , unsigned long long> sg_count(int index, int rngL, int rngR, int qL, int qR) {
	pair<unsigned long long, unsigned long long> p1, p2;
	if(qL > rngR || qR < rngL ) {
		return make_pair(0,10000000000000);
	}
	else if(qL <= rngL && qR >= rngR) {
		return sg_tree[index];
	}
	else {
		int mid = (rngR + rngL) / 2;
		p1 = sg_count(2*index + 1, rngL, mid, qL, qR);
		p2 = sg_count(2*index + 2, mid + 1, rngR, qL, qR);
		return make_pair(p1.first + p2.first , p1.second < p2.second ? p1.second : p2.second );
	}
}

void sg_update(int index, int rngL, int rngR, int ind, int val, int sig) {
	
	// cout << index << ", " << rngL << ", " << rngR << ", " << ind << ", " << val << "\n";
	if(ind < rngL || ind > rngR) {
		// cout << "rejected \n";
	}
	else if(rngR == rngL) {
		if(sig == 1){
			// cout << "old val : " << sg_tree[index].first << ". " << sg_tree[index].second << "\n";
			sg_tree[index].first += val;
			sg_tree[index].second += val;
			// cout << "adding\n";
			// cout << "new val : " << sg_tree[index].first << ". " << sg_tree[index].second << "\n";

		}
		else{
			sg_tree[index].first -= val;
			sg_tree[index].second -= val;
			// cout << "sub'ing\n";
		}
	}
	else {
		int mid = (rngR + rngL) / 2;
		sg_update(2*index + 1, rngL, mid, ind, val, sig);
		sg_update(2*index + 2, mid + 1, rngR, ind, val, sig);
		
		// cout << "ind : " << index << "\n";
		// cout << "child sums : " << sg_tree[2*index + 1].first << ", " <<  sg_tree[2*index + 2].first << "\n";

		sg_tree[index].first = sg_tree[2*index + 1].first + sg_tree[2*index + 2].first;
		sg_tree[index].second = sg_tree[2*index + 1].second < sg_tree[2*index + 2].second ? sg_tree[2*index + 1].second : sg_tree[2*index + 2].second ;
		// cout << "new val : " << sg_tree[index].first << ". " << sg_tree[index].second << "\n";

	}

}

int main() {

	unsigned long long int n, nn, pow = 2, tmp, q, t1, t2;
	pair<unsigned long long, unsigned long long > p;
	string str;
	cin >> n;
	nn = n;

	while(nn != 0) {
		pow = pow*2;
		nn = nn/2;
	}

	sg_tree.resize(pow, make_pair(0, 1000000000000) );
	for (int i=0;i<n;i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	build_sg(0, 0, n-1);

	cin >> q;

	for(int i=0;i<q;i++) {
		cin >> str >> t1 >> t2;
		if(str[0] == 'C') {
			p = sg_count(0, 0, n-1, t1, t2);
			cout << p.first - p.second << "\n";
		}
		else if(str[0] == 'E') {
			sg_update(0, 0, n-1, t2, t1, -1);
		}
		else if(str[0] == 'G') {
			sg_update(0, 0, n-1, t2, t1, +1);
		}
	
	}

	//print();

}