#include<stdio.h>
#include<math.h>
int N, A[100], Visited[100], x_pos[100],y_pos[100];
int mn;
int start_x,start_y,end_x,end_y;
void print()
{
    int i;
    int cost=0;

   cost+=abs(start_x-x_pos[A[0]])+abs(start_y-y_pos[A[0]]);

    for (i=1; i<N; i++)
    {
    cost+=abs(x_pos[A[i-1]]-x_pos[A[i]])+abs(y_pos[A[i-1]]-y_pos[A[i]]);
    }

    cost+=abs(end_x-x_pos[A[N-1]])+abs(end_y-y_pos[A[N-1]]);


    if(cost<mn) mn=cost;

}
void solve(int i)
{
    if (i == N)
    {
        print();
        return;
    }
    for (int j=0; j<N; j++) if (0 == Visited[j])
        {
            A[i] = j;
            Visited[j] = 1;
            solve(i+1);
            Visited[j] = 0;
        }
}
int main()
{
    freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int test=10;
    for(int t=1;t<=test;t++)
    {

        int i;
        scanf("%d", &N);
        scanf("%d%d%d%d",&start_x,&start_y,&end_x,&end_y);

        for(i=0; i<N; i++) scanf("%d%d",&x_pos[i],&y_pos[i]);

        for (i=0; i<N; i++)
            Visited[i] = 0;
        mn=1e6;
        solve(0);
        printf("# %d %d\n",t,mn);
    }
    return 0;
}

