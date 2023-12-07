#include<bits/stdc++.h>
using namespace std;
const int sz=22;
int grid[sz][sz];
int visited[sz][sz];
int level[sz][sz];
int N,C;
int bfs(int sx,int sy)
{

    visited[sx][sy]=1;
    level[sx][sy]=0;
    queue<pair<int,int>>q;
    q.push({sx,sy});
    int cnt=0,cost=0;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(grid[x][y]==2)
        {
            cnt++;

            cost=max(cost,level[x][y]);

            if(cnt==C)
            {  //cout<<cost<<endl;
                return cost;
            }
        }
        if(x-1>=0&&!visited[x-1][y]&&(grid[x-1][y]==1||grid[x-1][y]==2))
        {
            q.push({x-1,y});
            visited[x-1][y]=1;
            level[x-1][y]=level[x][y]+1;
        }
        if(x+1<=N&&!visited[x+1][y]&&(grid[x+1][y]==1||grid[x+1][y]==2))
        {
            q.push({x+1,y});
            visited[x+1][y]=1;
            level[x+1][y]=level[x][y]+1;
        }
        if(y-1>=0&&!visited[x][y-1]&&(grid[x][y-1]==1||grid[x][y-1]==2))
        {
            q.push({x,y-1});
            visited[x][y-1]=1;
            level[x][y-1]=level[x][y]+1;
        }
        if(y+1<=N&&!visited[x][y+1]&&(grid[x][y+1]==1||grid[x][y+1]==2))
        {
            q.push({x,y+1});
            visited[x][y+1]=1;
            level[x][y+1]=level[x][y]+1;
        }
    }
    return INT_MAX;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {

        cin>>N>>C;
        int x[C],y[C];
        for(int i=0; i<C; i++)cin>>x[i]>>y[i];
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                cin>>grid[i][j];
            }
        }
        for(int i=0; i<C; i++)
        {
            grid[x[i]][y[i]]=2;
        }

        int ans=INT_MAX;
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(grid[i][j]==1)
                { 
                  memset(visited,0,sizeof(visited));
                  memset(level,0,sizeof(level));

                    int cost;
                    cost=bfs(i,j);
                    ans=min(ans,cost);
                }
            }
        }
        cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}
