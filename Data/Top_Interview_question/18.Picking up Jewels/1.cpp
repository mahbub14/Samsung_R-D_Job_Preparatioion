#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int grid[N][N];
int visited[N][N];
int tmp[N][N];
int ans[N][N];
int jewel;
int n;
int mx;
void init()
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            ans[i][j]=grid[i][j]=tmp[i][j]=visited[i][j]=0;
        }
    }
}
void inputcase()
{

    cin>>n;
    init();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>grid[i][j];
            tmp[i][j]=grid[i][j];
        }
    }
}
bool isValid(int x,int y)
{
    return(x>=0&&x<n&&y>=0&&y<n&&!visited[x][y]&&(grid[x][y]==2||grid[x][y]==0));
}
void dfs(int x,int y)
{
    visited[x][y]=1;
    tmp[x][y]=3;
    if(grid[x][y]==2) jewel++;

    if(x==n-1&y==n-1&&mx<jewel)
    {
        mx=jewel;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans[i][j]=tmp[i][j];
            }
        }
        return;
    }
    if(isValid(x-1,y))
    {
        dfs(x-1,y);
        tmp[x-1][y]=grid[x-1][y];
        if(grid[x-1][y]==2) jewel--;
        visited[x-1][y]=0;
    }
    if(isValid(x+1,y))
    {
        dfs(x+1,y);
        tmp[x+1][y]=grid[x+1][y];
        if(grid[x+1][y]==2) jewel--;
        visited[x+1][y]=0;

    }
    if(isValid(x,y-1))
    {
        dfs(x,y-1);
        tmp[x][y-1]=grid[x][y-1];
        if(grid[x][y-1]==2) jewel--;
        visited[x][y-1]=0;
    }
    if(isValid(x,y+1))
    {
        dfs(x,y+1);
        tmp[x][y+1]=grid[x][y+1];
        if(grid[x][y+1]==2) jewel--;
        visited[x][y+1]=0;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        inputcase();
        mx=0;
        jewel=0;
        dfs(0,0);
        cout<<mx<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
