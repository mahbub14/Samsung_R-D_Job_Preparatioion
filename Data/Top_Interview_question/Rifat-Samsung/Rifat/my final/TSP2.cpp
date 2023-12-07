#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int A[100],Vis[100];
void ck(vector<vector<int>> &path){

    //int i;
    int cost = 0;
    for(int i=1;i<=n;i++){
        cost += path[A[i-1]][A[i]];
    }
    ans = min(ans,cost);

}

void solve(vector<vector<int>> &path, int i){
    if(i == n){
        ck(path);
        return;
    }
    for(int j=1;j<n;j++){
        if(Vis[j] == 0){
            A[i] = j;
            Vis[j] = 1;
            solve(path,i+1);
            Vis[j] = 0;
        }
    }

}


int main(){
    int test;
    cin>>test;
    for(int t=1;t<=test;t++){
        cin>>n;
        vector<vector<int>> path;

        for(int i=0;i<n;i++){
            vector<int> v;
            int x;
            for(int j=0;j<n;j++){
                cin>>x;
                v.push_back(x);
            }
            path.push_back(v);
        }
        memset(A,0,sizeof(A));
        memset(Vis,0,sizeof(Vis));
        ans = INT_MAX;
        solve(path,1);
        cout<<ans<<endl;


    }


}

