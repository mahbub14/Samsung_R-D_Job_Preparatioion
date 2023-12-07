#include<stdio.h>
int visited[100][100];
int grid[100][100];
int N,M,ex,ey;
void inputcase(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&grid[i][j]);
            if(3==grid[i][j]){
                ex=i;
                ey=j;
            }
            visited[i][j]=-1;
        }
    }
}
void solve(int x,int y,int lvl){
    if(visited[x][y]>=0&&lvl>=visited[x][y])
        return;
    visited[x][y]=lvl;
    if(grid[x][y]==3)
        return;
    if(y-1>=0&&grid[x][y-1])
        solve(x,y-1,lvl);
    if(y+1<M&&grid[x][y+1])
        solve(x,y+1,lvl);
    for(int i=1;x+i<N;i++)if(grid[x+i][y]){
        int mx=lvl>i?lvl:i;
        solve(x+i,y,mx);
        break;
    }
    for(int i=1;x-i>=0;i++){
        if(grid[x-i][y]){
            int mx=lvl>i?lvl:i;
            solve(x-i,y,mx);
            break;
        }
    }
}
void solvecase(){
    solve(N-1,0,0);

    printf("%d\n",visited[ex][ey]);
}
int main(){
    inputcase();
    solvecase();
}
