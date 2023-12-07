#include <stdio.h>
#define MAX 6
int X1[MAX], Y1[MAX], X2[MAX], Y2[MAX], d[MAX], visited[MAX];
int sx, sy, dx, dy;
int T, Case, N, Ans;
void readcase()
{
    int i;
    scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i], &d[i]);
        visited[i] = 0;
    }
}
void solve(int x, int y, int cost)
{
    int i, left, right;
    if (cost >= Ans)
        return;
    left = (dx > x) ? dx - x : x - dx;
    left += (dy > y) ? dy - y : y - dy;
    if (left + cost < Ans)
        Ans = left + cost;
    for (i = 0; i < N; i++) if (!visited[i])
    {
        visited[i] = 1;
        left = (X1[i] > x) ? X1[i] - x : x - X1[i];
        left += (Y1[i] > y) ? Y1[i] - y : y - Y1[i];
        right = (X2[i] > x) ? X2[i] - x : x - X2[i];
        right += (Y2[i] > y) ? Y2[i] - y : y - Y2[i];
        if (left < right)
            solve(X2[i], Y2[i], cost + left + d[i]);
        else
            solve(X1[i], Y1[i], cost + right + d[i]);
        visited[i] = 0;
    }
}
void solvecase()
{
    Ans = 999999999;
    solve(sx, sy, 0);
    printf ("#%d %d\n", Case, Ans);
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
