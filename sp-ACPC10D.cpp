#include <cstdio>

using namespace std;

int mn_num(int a, int b) {
	return (a < b ? a : b);
}

int main() {

	int ctr=0, rows, tmp, small;

	while(true) {
		scanf("%d", &rows);
		if(rows == 0)
			break; 
		ctr++;

		long arr[rows][3];

		for(int i=0;i<rows;i++) {
			for(int j=0;j<3;j++) {
				scanf("%ld", &arr[i][j]);
			}
		}

		// for (int i = 0; i < rows; ++i) {
		// 	for(int j=0;j<3;j++) {
		// 		printf("%d\t", arr[i][j]);
		// 	}
		// 	printf("\n");
		// }

		// printf("\n");

		arr[0][2] = arr[0][1] + arr[0][2];
		arr[1][0] = arr[0][1] + arr[1][0];
		arr[1][1] = mn_num( arr[1][0], mn_num( arr[0][2], arr[0][1] ) ) + arr[1][1];
		arr[1][2] = mn_num( arr[1][1], mn_num( arr[0][1], arr[0][2] ) ) + arr[1][2]; 

		for(int i=2;i<rows;i++) {
			for(int j=0;j<3;j++) {
				small = arr[i-1][j];
				if(j-1 >= 0)
					small = mn_num(small, arr[i-1][j-1]);
				if(j+1 < 3)
					small = mn_num(small, arr[i-1][j+1]);
			
				if(j-1 >= 0) 
					small = mn_num(small, arr[i][j-1]);

				arr[i][j] = arr[i][j] + small;

			}
		}

		// for (int i = 0; i < rows; ++i) {
		// 	for(int j=0;j<3;j++) {
		// 		printf("%d\t", arr[i][j]);
		// 	}
		// 	printf("\n");
		// }

		printf("%d. %ld\n", ctr, arr[rows-1][1]);

	}

}