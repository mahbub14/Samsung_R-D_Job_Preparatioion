#include <stdio.h>
#define MAXN 21
#define MAXR 5
int dist[MAXN][MAXN][MAXN], grid[MAXN][MAXN];
int X[MAXR], Y[MAXR], Ans, Max;
int T, Case, N, M, R;
void readcase()
{
    int i, j;
    scanf("%d %d %d", &N, &M, &R);
    for (i = 0; i < N; i++) for (j = 0; j < M; j++)
        scanf("%d", &grid[i][j]);
    for (i = 0; i < R; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
        grid[X[i]][Y[i]] = 2;
    }
}
void solve (int i, int j, int k, int cost)
{
    if (cost < dist[i][j][k])
        dist[i][j][k] = cost;
    else
        return;
    if (grid[i][j])
    {
        if (i - 1 >= 0)
            solve(i - 1, j, k, cost + 1);
        if (i + 1 < N)
            solve(i + 1, j, k, cost + 1);
        if (j - 1 >= 0)
            solve(i, j - 1, k, cost + 1);
        if (j + 1 < M)
            solve(i, j + 1, k, cost + 1);
    }
}
void solvecase()
{
    int i, j, k;
    Ans = 21 * 21;
    for (i = 0; i < N; i++) for (j = 0; j < M; j++) for (k = 0; k < R; k++)
        dist[i][j][k] = 21 * 21;
    for (i = 0; i < R; i++)
        solve(X[i], Y[i], i, 0);
    for (i = 0; i < N; i++) for (j = 0; j < M; j++) if (!grid[i][j])
    {
        Max = 0;
        for (k = 0; k < R; k++)
        {
            if (dist[i][j][k] > Max)
                Max = dist[i][j][k];
        }
        if (Max < Ans)
            Ans = Max;
    }
    if (21 * 21 == Ans)
        Ans = -1;
    printf("#%d %d\n", Case, Ans);
}
int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (Case = 1; Case <= T; Case++)
    {
        readcase();
        solvecase();
    }
    return 0;
}
