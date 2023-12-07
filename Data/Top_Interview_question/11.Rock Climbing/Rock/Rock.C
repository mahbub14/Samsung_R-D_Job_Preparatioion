#include <stdio.h>
#define MAX 51
int grid[MAX][MAX], dp[MAX][MAX];
int N, T, p, q, Case, Min, cons;
void readcase()
{
    int i, j;
    scanf ("%d", &N);
    for (i = 0; i < N; i++) for (j = 0; j < N; j++)
    {
        scanf ("%d", &grid[i][j]);
        dp[i][j] = 9999;
        if (3 == grid[i][j])
        {
            p = i;
            q = j;
        }
    }
}
void solve(int x, int y, int max, int count)
{
    if (0 == grid[x][y])
        count++;
    else
        count = 0;
    if (count > max)
        max = count;
    if(max >= dp[x][y])
        return;
    else
        dp[x][y] = max;
    if (x - 1 >= 0)
        solve(x - 1, y, max, count);
    if (x + 1 < N)
        solve(x + 1, y, max, count);
    if (y - 1 >= 0 && grid[x][y - 1])
        solve(x, y - 1, max, count);
    if (y + 1 < N && grid[x][y + 1])
        solve(x, y + 1, max, count);
}
void solvecase()
{
    solve(N - 1, 0, 0, 0);
}
void printcase()
{
    printf ("#%d %d\n", Case, dp[p][q]);
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
        printcase();
    }
    return 0;
}
