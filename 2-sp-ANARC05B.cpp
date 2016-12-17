#include <iostream>

using namespace std;

int main() {
	
	int a,b;

	while(true) {
		cin >> a;
		if(a == 0)
			break;
		else {
			int aseq[a];
			for (int i = 0; i < a; ++i) {
				cin >> aseq[i];
			}
			cin >> b;
			int bseq[b];
			for (int i = 0; i < b; ++i) {
				cin >> bseq[i];
			}

			int ap=0, bp=0;

			int asum = aseq[ap];
			int bsum = bseq[ap];

			int global = 0;

			while(ap < a && bp < b) {
				// cout << "ap : " << aseq[ap] << " bp : " << bseq[bp] <<  " asum : " << asum << " bsum : " << bsum << " global : " << global << "\n" ;
				if(aseq[ap] == bseq[bp]) {
					global += (asum > bsum) ? asum : bsum;
					asum = 0;
					bsum = 0;
					ap++;
					if(ap == a)
						break;
					else {
						asum += aseq[ap];
					} 

				}
				else if(aseq[ap] > bseq[bp]) {
					bp++;
					if(bp == b)
						break;
					else {
						bsum += bseq[bp];
					} 
				}
				else if(bseq[bp] > aseq[ap]) {
					ap++;
					if(ap == a)
						break;
					else {
						asum += aseq[ap];
					} 
				}
			}

			while(ap == a && bp < b) {
				bp++;
				if(bp == b)
					break;
				else {
					bsum += bseq[bp];
				}
			}

			while(bp == b && ap < a) {
				ap++;
				if(ap == a)
					break;
				else {
					asum += aseq[ap];
				}
			}

			global += (asum > bsum) ? asum : bsum;

			cout << global << "\n";
		}
	}

}