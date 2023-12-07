#include<bits/stdc++.h>
using namespace std;
int sx,sy,ex,ey;
int N,M;
int visited[100][100];
int level[100][100];
int ans;
bool isInside(int x, int y){
    if(x>=1&&x<=N&&y>=1&&y<=M)
        return true;
    return false;
}
void bfs(int sx,int sy){
    visited[sx][sy]=1;
    level[sx][sy]=0;
    queue<pair<int,int>>q;
    q.push({sx,sy});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        if(x==ex&&y==ey){
            ans=min(ans,level[x][y]);
        }
        if(isInside(x-2,y-1)&&!visited[x-2][y-1]){
            visited[x-2][y-1]=1;
            level[x-2][y-1]=level[x][y]+1;
            q.push({x-2,y-1});
        }
        if(isInside(x-1,y-2)&&!visited[x-1][y-2]){
            visited[x-1][y-2]=1;
            level[x-1][y-2]=level[x][y]+1;
            q.push({x-1,y-2});
        }
        if(isInside(x+1,y-2)&&!visited[x+1][y-2]){
            visited[x+1][y-2]=1;
            level[x+1][y-2]=level[x][y]+1;
            q.push({x+1,y-2});
        }
        if(isInside(x+2,y-1)&&!visited[x+2][y-1]){
            visited[x+2][y-1]=1;
            level[x+2][y-1]=level[x][y]+1;
             q.push({x+2,y-1});
        }
        if(isInside(x-2,y+1)&&!visited[x-2][y+1]){
            visited[x-2][y+1]=1;
            level[x-2][y+1]=level[x][y]+1;
            q.push({x-2,y+1});
        }
        if(isInside(x-1,y+2)&&!visited[x-1][y+2]){
            visited[x-1][y+2]=1;
            level[x-1][y+2]=level[x][y]+1;
            q.push({x-1,y+2});
        }
        if(isInside(x+1,y+2)&&!visited[x+1][y+2]){
            visited[x+1][y+2]=1;
            level[x+1][y+2]=level[x][y]+1;
            q.push({x+1,y+2});
        }
        if(isInside(x+2,y+1)&&!visited[x+1][y+1]){
            visited[x+2][y+1]=1;
            level[x+2][y+1]=level[x][y]+1;
            q.push({x+2,y+1});
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
    cin>>N>>M;
    cin>>sx>>sy>>ex>>ey;
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
    ans=1e4;
    bfs(sx,sy);
    cout<<ans<<endl;
    }
    return 0;
}
