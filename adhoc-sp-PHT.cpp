#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;

	for(int z=0;z<t;z++) {

		unsigned long long int num, j;
		cin >> num;

		// long low = 2, high = 1000000;

		// long mid = (low + high) / 2;


		// while( mid*(mid + 2) != num ) {
		// 	cout << (mid*(mid - 1)/4) << "\n";
		// 	// cout << mid << ", " << low << ", " << high << "\n";
		// 	if( mid*(mid + 2) > num ){
		// 		high = mid;
		// 	}
		// 	else {
		// 		low = mid;
		// 	}
		// 	mid = (low + high)/2;
		// }

		j = (sqrt(num+1) -1 );

		cout << "Case " << (z+1) << ": " << j << "\n"; 



		//cout << "Case " << (z+1) << ": " << ((int)sqrt(num+1) -1 ) << "\n"; 
	}
}

// #include <iostream>
// #include <cmath>

// using namespace std;

// int main() {
    
//     unsigned long long int n,t,i=0,j;
//     cin >> t;
    
//     while(t--) {
//         i++;
//         cin >> n;
//         j= sqrt(1+n) -1;
        
//         //printf("Case %llu: %llu\n",i,j);
//  		cout << "Case " << i << ": " << j << "\n";
 
//     }
//     return 0;
// }