// Rock_input.c
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
	int T, Case;
	int N;
	int Grid[51][51];
	int x, y;
	int i, j;
	mSeed = 3;
	T = 50;
	freopen("Rock_input.txt", "w", stdout);
	printf("%d\n", T);
	for (Case = 1; Case <= T; Case++) {
		if (Case < 5)
			N = Case + 4;
		else
			N = mrand(46) + 5;
		printf("\n%d\n", N);
		for (i = 0; i < N; i++) for (j = 0; j < N; j++)
			Grid[i][j] = mrand(2);
		x = mrand(N);
		y = mrand(N);
		Grid[x][y] = 3;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				printf("%d ", Grid[i][j]);
			printf("\n");
		}
	}
	return 0;
}
