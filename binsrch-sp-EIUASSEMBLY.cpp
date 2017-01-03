#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool srt(pair<unsigned long long, unsigned long long> a, pair<unsigned long long, unsigned long long> b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

int main() {

	unsigned long long t, r, k, p, m, sumamt, max, min, lo, hi, mid, kk;
	bool agree;
	vector< pair<unsigned long long, unsigned long long> > a;
	
	cin >> t;

	for(int z=0;z<t;z++) {

		cin >> r >> k;
		a.clear();
		max = 0, sumamt = 0, min = -1;

		for(int i=0;i<r;i++) {
			cin >> p >> m;
			a.push_back(make_pair(p, m));
			sumamt += m;
			if(max < p)
				max = p;
			if(min == -1 || min > p)
				min = p;
		}

		lo = min;
		hi = max + (k/sumamt);

		// cout << "max product : " << max << "\n";
		// cout << "min product : " << min << "\n\n";

		// cout << "lo : " << lo << "\n";
		// cout << "hi : " << hi << "\n\n";

		// cout << "sum : " << sumamt << "\n";

		while(lo < hi) {
			mid = lo + (hi-lo + 1) / 2;
			// cout << "hi : " << hi << "lo : " << lo << "mid : " << mid << "\n";

			agree = true;
			int i;
			kk = k;
			// cout << "kk : " << kk << "\n";
			for(i =0;i<r;i++) {
				if(mid < a[i].first){
					continue;
				}
				else {
					if(kk < a[i].second*(mid - a[i].first)) {
						i = 0;
						break;
					}
					else
						kk = kk - a[i].second*(mid - a[i].first);
				} 
				// cout << "kk : " << kk << "\n";

			}


			if(i == r)
				lo = mid;
			else
				hi = mid - 1;
		}

		cout << hi << "\n";





	}

}