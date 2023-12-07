#include<bits/stdc++.h>
using namespace std;
int cost[1000],t[1000];
#define inf 9999999
int dp[4010][1010][12];
int solve(int h,int d, int n){
    //h= my stemina
    //d = distance to cover
    // n = nth cost time
    if(h<0 || n < 0)
        return inf;
    if(d == 0)
        return 0;

    if(dp[h][d][n] != -1)
        return dp[h][d][n];

    dp[h][d][n] = min(solve(h,d,n-1), t[n] + solve(h-cost[n],d-1,n));
    //dp[H][D][k]=min(solve(H,D,k-1,cost,time),time[k]+solve(H-cost[k],D-1,k,cost,time));

    return dp[h][d][n];




}

int main(){
    int n,h,d;
    cin>>h>>d>>n;
    for(int i=0;i<n;i++){
        cin>>cost[i]>>t[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans = solve(h,d,n-1);

    cout<<ans<<endl;



}
