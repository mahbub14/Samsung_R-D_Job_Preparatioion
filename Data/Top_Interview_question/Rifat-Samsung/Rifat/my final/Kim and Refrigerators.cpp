#include<bits/stdc++.h>
using namespace std;
int n, A[100],Vis[100];
int x[100],y[100];
int sx,sy,ex,ey,ans;
void ck(){

    int i;
    int cost = 0;
    cost += abs(sx-x[A[0]]) + abs(sy-y[A[0]]);

    for(int i=1;i<n;i++){
        cost += abs(x[A[i-1]]- x[A[i]]) + abs(y[A[i-1]]- y[A[i]]);

    }

    cost += abs(ex-x[A[n-1]]) + abs(ey-y[A[n-1]]);

    ans = min(ans,cost);



}


void solve(int i){
    if(i == n){
        ck();
        return;
    }
    for(int j=0;j<n;j++){
        if(Vis[j] == 0){
            A[i] = j;
            Vis[j] = 1;
            solve(i+1);
            Vis[j] = 0;
        }
    }


}


int main(){

    freopen("/home/rifat/Desktop/Samsung/Top_Interview_question (2)/Top_Interview_question/07.Kim and Refrigerators or A delivery boy/TSP-input.txt","r",stdin);
    int test=10;
    cin>>test;
    for(int t=1;t<=test;t++){
        cin>>n;
        cin>>sx>>sy;
        cin>>ex>>ey;

        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }

        memset(A,0,sizeof(A));
        memset(Vis,0,sizeof(Vis));
        ans = INT_MAX;
        solve(0);
        printf("# %d %d\n",t,ans);


    }
}
