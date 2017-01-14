#include <cstdio>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);

	int a, max = 0, streak = 0, ones = 0;

	for(int i=0;i<t;i++) {
		scanf("%d", &a);
		
		if(a == 0)
			streak++;
		else{
			streak--;
			ones++;
		}

		if(streak <=0)
			streak = 0;
		else if(streak > max)
			max = streak;


		//printf("1s : %d, streak : %d, max : %d\n", ones, streak, max);
	}
	if(max != 0)
		printf("%d\n", (ones + max) );
	else
		printf("%d\n", (ones -1) );

}