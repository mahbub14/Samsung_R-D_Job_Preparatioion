#include<stdio.h>

#define inf 50000
int n,m,s;
int ara[25][25];
int rare[5][2],queue[2000][3];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int distance(int x,int y)
{
    int vis[n+1][m+1];
    int i,j,cnt=0,fr,en;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            vis[i][j]=0;
        }
    }
    fr = 0;
    en = 1;
    vis[x][y]=1;
    queue[fr][0]=x;
    queue[fr][1]=y;
    queue[fr][2]=0;
    while(fr<en){
        x = queue[fr][0];
        y = queue[fr][1];
        int z = queue[fr][2];
        fr++;
        if(ara[x][y]==2){
            cnt++;
            if(cnt==s)return z;
        }
        for(i=0;i<4;i++){
            int fx = dx[i]+x;
            int fy = dy[i]+y;
            if(fx>0 && fx<=n && fy>0 && fy<=m && vis[fx][fy]==0 && ara[fx][fy]){
                vis[fx][fy]=1;
                queue[en][0]=fx;
                queue[en][1]=fy;
                queue[en++][2]=z+1;
            }
        }
    }
    //return -1;
}

int solve()
{
    int i,j,k;
    int ans = inf;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            int tmp = distance(i,j);
            //printf("%d\n",tmp);
            if(tmp<ans)ans = tmp;
        }
    }
    return ans;
}



int main()
{

    int t,cs=1,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&s);
       // m=n;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        for(i=0;i<s;i++){
            scanf("%d %d",&rare[i][0],&rare[i][1]);
            rare[i][0]++;
            rare[i][1]++;
        }
        for(i=0;i<s;i++){
            ara[rare[i][0]][rare[i][1]]=2;
        }
        printf("#%d %d\n",cs++,solve());
    }
    return 0;
}
