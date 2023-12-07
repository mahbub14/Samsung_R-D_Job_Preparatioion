#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int grid[N][N];
int visited[N][N];
int level[N][N];
int n,m;
int ans;
void bfs(pair<int,int>src){
    visited[src.first][src.second]=1;
    level[src.first][src.second]=1;
    queue<pair<int,int>>q;
    q.push({src.first,src.second});
    while(!q.empty()){
        pair<int,int>head=q.front();
        q.pop();
        int x=head.first;
        int y=head.second;

        if(x-1>=0&&visited[x-1][y]==0&&grid[x-1][y]==1){
            q.push({x-1,y});
            visited[x-1][y]=1;
            ans=level[x-1][y]=level[x][y]+1;
        }
        if(x+1<n&&visited[x+1][y]==0&&grid[x+1][y]==1){
            q.push({x+1,y});
            visited[x+1][y]=1;
            ans=level[x+1][y]=level[x][y]+1;
        }
        if(y-1>=0&&visited[x][y-1]==0&&grid[x][y-1]==1){
            q.push({x,y-1});
            visited[x][y-1]=1;
            ans=level[x][y-1]=level[x][y]+1;
        }
        if(y+1<m&&visited[x][y+1]==0&&grid[x][y+1]==1){
            q.push({x,y+1});
            visited[x][y+1]=1;
            ans=level[x][y+1]=level[x][y]+1;
        }
    }
}
int main(){
    int t;
	cin >> t;

	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];

		int x, y;
		cin >> x >> y;
		ans=0;
		memset(visited,0,sizeof(visited));
		pair<int,int>src={x-1,y-1};
		bfs(src);
		cout << ans << "\n";
	}
	return 0;
}
