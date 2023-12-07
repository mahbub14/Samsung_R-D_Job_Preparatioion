#include <stdio.h>
#define MAX 6
int visited[MAX];
int X1[MAX], Y1[MAX], X2[MAX], Y2[MAX], d[MAX];
int sx, sy, ex, ey;
int T, Case, N, Ans;

void readcase()
{
	int i;
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i], &d[i]);
		visited[i] = 0;
	}
}

void solve(int x, int y, int dif)
{
	int i, min = dif, d1, d2;
	min += (ex > x) ? ex - x : x - ex;
	min += (ey > y) ? ey - y : y - ey;
	if (min < Ans)
		Ans = min;
	for (i = 0; i < N; i++) if (!visited[i])
	{
		visited[i] = 1;
		d1 = (x > X1[i]) ? x - X1[i] : X1[i] - x;
		d1 += (y > Y1[i]) ? y - Y1[i] : Y1[i] - y;
		d2 = (x > X2[i]) ? x - X2[i] : X2[i] - x;
		d2 += (y > Y2[i]) ? y - Y2[i] : Y2[i] - y;
		if (d1 < d2)
			solve(X2[i], Y2[i], dif + d1 + d[i]);
		else
			solve(X1[i], Y1[i], dif + d2 + d[i]);
		visited[i] = 0;
	}

	
}
void solvecase()
{
	Ans = 9999999;
	solve(sx, sy, 0);
	printf("#%d %d\n", Case, Ans);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++)
	{
		readcase();
		solvecase();
	}
	return 0;
}