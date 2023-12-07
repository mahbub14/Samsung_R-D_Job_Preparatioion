// Rock.c
#include<stdio.h>
#define SIZE 51
#define INF (SIZE*SIZE)
int T;
int Case;
int N;
int Grid[SIZE][SIZE];
int dp[SIZE][SIZE];
int X, Y;
void readCase() {
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &Grid[i][j]);
			if (3 == Grid[i][j]) {
				X = i;
				Y = j;
			}
		}
	}
}
void solve(int x, int y, int maxzero, int curzero) {
	if (0 == Grid[x][y])
		curzero++;
	else
		curzero = 0;
	if (curzero > maxzero)
		maxzero = curzero;
	if (maxzero < dp[x][y])
		dp[x][y] = maxzero;
	else
		return;
	if (x - 1 >= 0)
		solve(x - 1, y, maxzero, curzero);
	if (x + 1 < N)
		solve(x + 1, y, maxzero, curzero);
	if (y - 1 >= 0 && Grid[x][y - 1])
		solve(x, y - 1, maxzero, curzero);
	if (y + 1 < N && Grid[x][y + 1])
		solve(x, y + 1, maxzero, curzero);
}
void solveCase() {
	int i, j;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++)
		dp[i][j] = INF;
	solve(N - 1, 0, 0, 0);
	if (INF == dp[X][Y])
		dp[X][Y] = -1;
}
void printCase() {
	printf("#%d %d\n", Case, dp[X][Y]);
}
int main() {
	freopen("Rock_input.txt", "r", stdin);
	freopen("Rock_output.txt", "w", stdout);
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
