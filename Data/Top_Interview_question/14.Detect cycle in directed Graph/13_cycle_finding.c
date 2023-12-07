#include<stdio.h>
#define SIZE 100
int T, N, M;
int Path[SIZE][SIZE];
int color[SIZE];
int parent[SIZE];
int first, end, Case;

void init()
{
    int i, j;
    for(i=0; i<=N; i++)
        for(j=0; j<=N; j++)
        Path[i][j] = 0;

    for(i=0; i<=N; i++)
    {
        color[i] = 0;
        parent[i] = -1;
    }
}

void input()
{
    int i, x, y;
    scanf("%d %d",&N, &M);
    init();
    for(i=0; i<M; i++)
    {
        scanf("%d %d", &x, &y);
        Path[x][y] = 1;
    }
}
int dfs(int i)
{
    int j;
    color[i] = 1;
    for(j=0; j<=N; j++) if(Path[i][j])
    {
        if(!color[j])
        {
            parent[j] = i;
            color[j] = 1;
            if(dfs(j))
                return 1;
        }
        else if(1 == color[j])
        {
            first = j;
            end = i;
            return 1;
        }
    }

    color[i] = -1;
    return 0;
}

void solveCase()
{
    int i;
    first = -1;
    for(i=0; i<=N; i++) if(!color[i])
         if(dfs(i))
             break;
}
void output()
{
    int i, j= 0;
    if(first == -1)
        printf("#%d -1\n", Case);
    else
    {
        printf("#%d %d", Case, end);
        for(i=end; i != first; i = parent[i])
        {
            printf(" %d", parent[i]);
        }
        printf("\n");
    }
}

int main()
{
    freopen("13.cycle_input.txt", "r", stdin);;
    scanf("%d", &T);
    for(Case = 1; Case <= T; Case++)
    {
        input();
        solveCase();
        output();
    }

    return 0;
}
