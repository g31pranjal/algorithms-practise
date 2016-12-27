#include <iostream>
#include <deque>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool canbe_sort( tuple<int,int,char> b, tuple<int,int,char> a ) {
	return get<2>(a) > get<2>(b);
}

int main() {

	int r, c;
	string str;

	int counter = 0;

	vector< vector<char> > a;
	vector<tuple<int,int,char> > canbe;
	deque<tuple<int,int,int> > order;
	tuple<int,int,char> loc;

	int global = 0, rp, cp, chain, chr, steps, goal;
	
	while(true) {
		cin >> r >> c;
		//cout << "r,c " << r << c << "\n";
		if(r==0 || c == 0)
			break;
		else {

			canbe.clear();
			a.clear();
			a.resize(r, vector<char> (c,'\n') );

			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					cin >> a[i][j];
					canbe.push_back(make_tuple(i,j,a[i][j]));
				}
			}

			// for(int i=0;i<r;i++) {
			// 	for(int j=0;j<c;j++) {
			// 		cout << i << "," << j << "," << a[i][j] << "\t\t";
			// 	}
			// 	cout << "\n";
			// }

			sort(canbe.begin(), canbe.end(), canbe_sort);
			// for(int i=0;i<canbe.size();i++) {
			// 	printf("%c at %d, %d\n", get<2>(canbe[i]), get<0>(canbe[i]), get<1>(canbe[i]) );
			// }


			while(!canbe.empty()) {
				loc = canbe.back();
				canbe.pop_back();
				order.clear();

				if(a[get<0>(loc)][get<1>(loc)] == 'A') {
					goal = 1;
					steps = 1;
					break;
				}

				order.push_front(make_tuple( get<0>(loc), get<1>(loc), 1 ));
				goal = 0;
				steps = 0;

				while(!order.empty()) {
					loc = order.front();				
					order.pop_front();
					rp = get<0>(loc);
					cp = get<1>(loc);
					chain = get<2>(loc);
					chr = a[rp][cp];

					// printf("popping info : %d,%d,%d,%c\n" , rp, cp, chain, chr);

					if((rp-1) >= 0 && a[rp - 1][cp] == chr-1) {
						if(a[rp - 1][cp] == 'A') {
							goal = 1;
							steps = chain + 1;
							break;
						}
						order.push_front(make_tuple(rp-1, cp, chain+1 ));
						// printf("-- pushing info : %d,%d,%d,%c\n", rp-1, cp, chain+1,chr-1);
					}
					if((rp-1) >= 0 && (cp-1) >=0 && a[rp - 1][cp - 1] == chr-1) {
						if(a[rp - 1][cp - 1] == 'A') {
							goal = 1;
							steps = chain + 1;
							break;
						}
						order.push_front(make_tuple(rp-1, cp-1, chain+1 ))  ;
						// printf("-- pushing info : %d,%d,%d,%c\n", rp-1, cp-1, chain+1,chr-1);

					}
					if((rp-1) >= 0 && (cp+1) < c && a[rp - 1][cp + 1] == chr-1) {
						if(a[rp - 1][cp + 1] == 'A') {
							goal = 1;
							steps = chain + 1;
							break;							
						}
						order.push_front(make_tuple(rp-1, cp+1, chain+1 ));
						// printf("-- pushing info : %d,%d,%d,%c\n", rp-1, cp+1, chain+1,chr-1);
					}
					if((rp+1) < r && a[rp + 1][cp] == chr-1) {
						if(a[rp + 1][cp] == 'A') {
							goal = 1;
							steps = chain + 1;
						}
						order.push_front(make_tuple(rp+1, cp, chain+1 ));
						// printf("-- pushing info : %d,%d,%d,%c\n", rp+1, cp, chain+1,chr-1);
					}
					if((cp-1) >=0 && (rp+1) < r && a[rp + 1][cp - 1] == chr-1) {
						if(a[rp + 1][cp - 1] == 'A') {
							goal = 1;
							steps = chain + 1;
							break;							
						}
						order.push_front(make_tuple(rp+1, cp-1, chain+1) );
						// printf("-- pushing info : %d,%d,%d,%c\n", rp+1, cp-1, chain+1,chr-1);
					}
					if((cp+1) < c && (rp+1) < r && a[rp + 1][cp + 1] == chr-1) {
						if(a[rp + 1][cp + 1] == 'A') {
							goal = 1;
							steps = chain + 1;
							break;							
						}
						order.push_front(make_tuple(rp+1, cp+1, chain +1 ) );
						// printf("-- pushing info : %d,%d,%d,%c\n", rp+1, cp+1, chain+1,chr-1);
					}
					if((cp-1) >=0 && a[rp][cp - 1] == chr-1) {
						if(a[rp][cp - 1] == 'A') {
							goal = 1;
							steps = chain + 1;
							break;							
						}
						order.push_front(make_tuple(rp, cp-1, chain + 1  ) );
						// printf("-- pushing info : %d,%d,%d,%c\n", rp, cp-1, chain+1,chr-1);
					}
					if((cp+1) < c && a[rp][cp + 1] == chr-1) {
						if(a[rp][cp + 1] == 'A') {
							goal = 1;
							steps = chain + 1;
							break;							
						}
						order.push_front(make_tuple(rp, cp+1, chain + 1 ) );
						// printf("-- pushing info : %d,%d,%d,%c\n", rp, cp+1, chain+1,chr-1);
					}
				}

				if(goal == 1)
					break;

			}

			printf("Case %d: %d\n", ++counter, steps);
			
		}
	}
}