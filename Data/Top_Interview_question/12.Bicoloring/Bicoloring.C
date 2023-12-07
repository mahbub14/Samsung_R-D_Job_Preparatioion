#include <stdio.h>
#define MAX 201
int path[MAX][MAX], Color[MAX];
int N, M;
int T, Case, Ans;
void readcase()
{
    int i, j, x, y;
    for (i = 0; i < N; i++)
    {
        Color[i] = 0;
        for (j = 0; j < N; j++)
            path[i][j] = 0;
    }
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        path[x][y] = path[y][x] = 1;
    }
}
void solve(int i, int c)
{
    int j;
    if (0 == Color[i])
        Color[i] = c;
    else if (c == Color[i])
        return;
    else if (3 - c == Color[i])// 2 bosbo kintu 1 ase 
    {
        Ans = 0;
        return;
    }
    for (j = 0; j < N; j++) if (path[i][j])
        solve(j, 3 - c);
}
void solvecase()
{
    int i;
    Ans = 1;
    for (i = 0; i < N; i++) if (!Color[i])
    {
        solve(i, 1);
        if (!Ans)
            return;
    }
}
void printcase()
{
    if (Ans)
        printf("BICOLORABLE.\n");
    else
        printf("NOT BICOLORABLE.\n");
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(scanf("%d", &N) && N)
    {
        readcase();
        solvecase();
        printcase();
    }
    return 0;
}
