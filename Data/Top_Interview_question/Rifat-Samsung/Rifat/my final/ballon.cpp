#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>v){
    int n = v.size();
    v.push_back(1);
    v.insert(v.begin(),1);
    int dp[n+2][n+2];
    memset(dp,0,sizeof(dp));
    for(int i=n;i>0;i--){
        for(int j=1;j<=n;j++){
            if(i>j) continue;
            int maxi = 0;

            for(int k=i;k<=j;k++){
                int cost = dp[i][k-1]+dp[k+1][j];

                if(i == 1 && j == n)
                    cost+=v[k];
                else
                    cost += v[i-1]* v[j+1];
                maxi = max(maxi,cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];


}

int main(){
    int test=1;
    //cin>>test;
    for(int t=1;t<=test;t++){
        int n,x;
        vector<int> v;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }

        cout<<solve(v)<<endl;

    }


}
