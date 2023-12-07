#include <stdio.h>
#define MAX 6
int visited[MAX];
int X1[MAX], Y1[MAX], X2[MAX], Y2[MAX], d[MAX];
int sx, sy, ex, ey;
int T, Case, N, Ans;

void readcase()
{
	int i;
    scanf("%d", &N);
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i], &d[i]);
		visited[i] = 0;
	}
}

void solve(int x, int y, int dif)
{
	int i, min = dif, d1, d2;
	min += abs(ex -x);
	min += abs(ey - y);
	if (min < Ans)
		Ans = min;
	for (i = 0; i < N; i++) if (!visited[i])
	{
		visited[i] = 1;
		d1 = abs(x -X1[i])+abs(y - Y1[i]);
		d2 = abs(x-X2[i])+abs(y-Y2[i]);
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

	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++)
	{
		readcase();
		solvecase();
	}
	return 0;
}
