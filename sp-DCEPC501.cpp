#include <cstdio>

using namespace std;

int t, n, tmp;

int main() {

	scanf("%d", &t);

	while(t--) {

		scanf("%d", &n);
		int a[n] = {0};
		long long int comp[n+1] = {0}, max[n+1] = {0};
		

		for(int i=0;i<n;i++) {
			scanf("%d", &a[i]);
			comp[i+1] = max[i+1] = -1;
		}

		for(int i=1;i<=n;i++) {
			if(i%2 != 0) {
				// odd
				if(i-1 >= 0 && (comp[i-1]+a[i-1]) > max[i] )
					max[i] =   (comp[i-1]+a[i-1]);
				if(i-3 >= 0 && (comp[i-3]+a[i-1]+a[i-2]+a[i-3]) > max[i] )
					max[i] =   (comp[i-3]+a[i-1]+a[i-2]+a[i-3]);
				if(i-3 >= 0 && (comp[i-3]+a[i-2]+a[i-3]) > max[i] )
					max[i] =   (comp[i-3]+a[i-2]+a[i-3]);
				if(i-5 >= 0 && (comp[i-5]+a[i-5]+a[i-4]+a[i-3]) > max[i] )
					max[i] =   (comp[i-5]+a[i-5]+a[i-4]+a[i-3]);
			}
			else {
				//even
				if(i-2 >= 0 && (comp[i-2]+a[i-2]) > comp[i] ) 
					comp[i] =  (comp[i-2]+a[i-2]);
				
				if(i-4 >= 0 && (comp[i-4]+a[i-4]+a[i-3]) > comp[i] ) 
					comp[i] =  (comp[i-4]+a[i-4]+a[i-3]);
				
				if(i-6 >= 0 && (comp[i-6]+a[i-6]+a[i-5]+a[i-4]) > comp[i] ) 
					comp[i] =  (comp[i-6]+a[i-6]+a[i-5]+a[i-4]);
				
				max[i] = comp[i];

				if(i-2 >= 0 && (comp[i-2]+a[i-1]+a[i-2]) > max[i] )
					max[i]  =  (comp[i-2]+a[i-1]+a[i-2]);
				
				if(i-4 >= 0 && (comp[i-4]+a[i-4]+a[i-3]+a[i-2]) > max[i] )
					max[i] =   (comp[i-4]+a[i-4]+a[i-3]+a[i-2]);
				
			
			}
		}

		printf("%lld\n", max[n]);

	}

}	