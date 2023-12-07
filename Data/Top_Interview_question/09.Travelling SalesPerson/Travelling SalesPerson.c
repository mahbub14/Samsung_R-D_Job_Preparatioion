#include <stdio.h>
#include <math.h>
int N, A[100], Visited[100], M[100][100];
int mn;
void print()
{
    int i;
    int cost=0;
    for(i=1;i<=N;i++)
    {


        cost+=M[A[i-1]][A[i]];
    }

    if(cost<=mn)
        mn = cost;
}

void solve(int i)
{
    if(i==N)
    {
        print();
        return;
    }
    for (int j=1; j<N; j++)
    {
        if (Visited[j] == 0)
        {
            A[i] = j;
            Visited[j] = 1;
            solve(i + 1);
            Visited[j] = 0;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &N);
        int i, j;
        for (i=0;i<N;i++)
        {
            for (j=0;j<N;j++)
            {
                scanf("%d",&M[i][j]);
            }
        }
        A[0]=0;
        A[N]=0;
        for (i=1;i<=N;i++)
        {
            Visited[i] = 0;
        }
        mn = 1e6;
        solve(1);
        printf("%d\n", mn);
    }
    return 0;
}
