// SpaceShip_input.c
#include<stdio.h>

static int mSeed;
static int mrand(int num)
{
	mSeed = mSeed * 1103515245 + 37209;
	if (mSeed < 0) mSeed *= -1;
	return ((mSeed >> 8) % num);
}

int main()
{
	int T, N, Case;
	int i, j, board[101][5];
	mSeed = 3;
	T = 50;
	freopen("SpaceShip_input.txt", "w", stdout);
	printf("%d\n", T);
	for (Case = 1; Case <= T; Case++) {
		if (Case < 5)
			N = 5 + Case;
		else if (Case < 30)
			N = mrand(98) + 3;
		else
			N = 100;
		printf("\n%d\n", N);
		for (i = 0; i < N; i++) {
			for (j = 0; j < 5; j++)
				printf("%d ", mrand(3));
			printf("\n");
		}
	}
	return 0;
}
