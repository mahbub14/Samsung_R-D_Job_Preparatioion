#include<bits/stdc++.h>
using namespace std;


int grid[55][55], dp[55][55];
int n,m;
int x,y;
int cnt=0;
void read_case(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            dp[i][j] = 9999;
            if(grid[i][j] == 3){
                x = i;
                y = j;
            }
        }
    }
}
void solve(int row, int col, int mx, int lvl){
    if(grid[row][col] == 0)
        lvl++;
    else
        lvl = 0;
    if(lvl>mx)
        mx = lvl;
    if(mx>=dp[row][col])
        return;
    else
        dp[row][col] = mx;

    if(row-1>=0)
        solve(row-1,col,mx,lvl);
    if(row+1<n)
        solve(row+1,col,mx,lvl);
    if(col-1>=0 && grid[row][col-1])
        solve(row,col-1,mx,lvl);
    if(col+1<n && grid[row][col+1])
        solve(row,col+1,mx,lvl);



}


int main(){
    freopen("/home/rifat/Desktop/Samsung/Top_Interview_question (2)/Top_Interview_question/11.Rock Climbing/Rock/Rock_climbing_input.txt","r",stdin);

    int test;
    cin>>test;
    for(int t=1;t<= test;t++){
        read_case();
        solve(n-1,0,0,0);
        printf ("#%d %d\n", t, dp[x][y]);


    }

}
