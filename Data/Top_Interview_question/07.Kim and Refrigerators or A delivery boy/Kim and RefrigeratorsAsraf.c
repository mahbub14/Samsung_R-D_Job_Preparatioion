#include <stdio.h>
#define MAX 13
int diff[MAX][MAX];
int x[MAX], y[MAX], visited[MAX], permu[MAX];
int N, T, Case, Min;

void readcase()
{
    int i;
    scanf ("%d", &N);
    scanf ("%d %d", &x[0], &y[0]);
    scanf ("%d %d", &x[N + 1], &y[N + 1]);
    for (i = 1; i <= N; i++)
        scanf ("%d %d", &x[i], &y[i]);
}
int dist(int index1, int index2)
{
    int d;
    d = (x[index1] > x[index2]) ? x[index1] - x[index2] : x[index2] - x[index1];
    d += (y[index1] > y[index2]) ? y[index1] - y[index2] : y[index2] - y[index1];
    return d;
}
void init()
{
    int i, j;
    for (i = 0; i <= N + 1; i++)
    {
        visited[i] = 0;
        for (j = 0; j <= N + 1; j++)
            diff[i][j] = dist(i, j);
    }
}
void solve(int i, int sum)
{
    int j;
    if (sum >= Min)
        return;
    if (i == N + 1)
    {
        sum += diff[permu[i - 1]][i];
        if (sum < Min)
            Min = sum;
        return;
    }
    for (j = 1; j <= N; j++) if (!visited[j])
    {
        visited[j] = 1;
        permu[i] = j;
        solve(i + 1, sum + diff[permu[i - 1]][permu[i]]);
        visited[j] = 0;
    }
}
void solvecase()
{
    init();
    permu[0] = 0;
    Min = 9999;
    solve(1, 0);
}
void printcase()
{
    printf ("#%d %d\n", Case, Min);
}
int main()
{
    freopen("TSP-input.txt", "r", stdin);
    freopen("TSP-output.txt", "w", stdout);
    scanf("%d",&T);
    for (Case = 1; Case <= T; Case++)
    {
        readcase();
        solvecase();
        printcase();
    }
    return 0;
}
