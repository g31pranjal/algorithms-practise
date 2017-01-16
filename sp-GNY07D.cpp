#include <cstdio>

using namespace std;

int main() {

	int t, r, c, dgt, ltr, pr, pc, dir, wgt, num, ind, nindx;
	char a[500];
	scanf("%d", &t);

	for(int z=1;z<=t;z++) {

		printf("%d ", z);

		scanf("%d%d%s", &r, &c, a);

		// printf("r : %d, c: %d, a : %s\n", r, c, a);

		dgt = (r*c);
		ltr = dgt/5;

		pr=0, pc=0;
		// 0 : -> , 1 : down , 2 : left , 3 : up
		dir=0;

		wgt = 16;
		num = 0;

		while(ltr) {

			// printf("dir : %d, pr : %d, pc : %d\n", dir, pr, pc);

			ind = c*pr + pc;
			num = num + wgt*(a[ind]-48);
			// printf("ele : %c, num : %d\n",a[ind] ,num);
			a[ind] = '\0';
			wgt = wgt/2;

			if(wgt == 0) {
				if(num == 0)
					printf(" ");
				else
					printf("%c", (64+num) );
				wgt = 16;
				ltr--;
				num = 0;
			}
			
			if(dir == 0) {
				nindx = c*pr + (pc+1);
				// printf("in right, nindx : %d\n", nindx);
				if(a[nindx] == '\0' || pc+1 == c) {
					dir = (dir+1)%4;
					pr++;
					continue;
				}
				pc++;
			}
			else if(dir == 1) {
				nindx = c*(pr+1) + (pc);
				if(a[nindx] == '\0' || pr+1 == r) {
					dir = (dir+1)%4;
					pc--;
					continue;
				}
				pr++;
			}
			else if(dir == 2) {
				nindx = c*(pr) + (pc-1);
				if(a[nindx] == '\0' || pc-1 == -1) {
					dir = (dir+1)%4;
					pr--;
					continue;
				}
				pc--;
			}
			else if(dir == 3) {
				nindx = c*(pr-1) + (pc);
				if(a[nindx] == '\0' || pr-1 == -1) {
					dir = (dir+1)%4;
					pc++;
					continue;
				}
				pr--;
			}
		}

		printf("\n");
	}
}