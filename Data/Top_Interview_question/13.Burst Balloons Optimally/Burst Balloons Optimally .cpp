#include <iostream>
using namespace std;


int n,ara[10],dp[2005],mm;

int Set(int p,int i){return p=p|1<<i;}
bool check(int p,int i){return ~p&1<<i;}

int dp_cal(int cur){
    if(cur>mm)return 0;
    if(dp[cur]!=-1)return dp[cur];
    int ans=0;
    for(int i=0;i<n;i++){
        if(check(cur,i)){
            int left=-1,right=-1;
            int ncur = Set(cur,i);
            for(int j=i-1;j>=0;j--){
                if(check(ncur,j)){
                    left = ara[j];
                    //ncur = Set(ncur,j);
                    break;
                }
            }
            for(int j=i+1;j<n;j++){
                if(check(ncur,j)){
                    right = ara[j];
                    //ncur = Set(ncur,j);
                    break;
                }
            }
            int sum = 0;
            if(left!=-1 && right!=-1)sum = left*right;
            else if(left!=-1) sum = left;
            else if(right!=-1) sum = right;
            else sum = ara[i];
            ans = max(ans,sum+dp_cal(ncur));
        }
    }

    return dp[cur]=ans;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("Balloon_input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ara[i];
            mm = Set(mm,i);
        }
        for(int i=0;i<2005;i++)dp[i]=-1;
        cout<<dp_cal(0)<<endl;
    }

    //cout<<mm<<endl;
    //cout<<check(5,1);
    return 0;
}
