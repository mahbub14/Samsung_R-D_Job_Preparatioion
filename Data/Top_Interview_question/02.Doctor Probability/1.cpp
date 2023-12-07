#include<iostream>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int nodes,edges,time;
        cin>>nodes>>edges>>time;
        double divshion[100][100]={0, };
        double table[100][100]={0, };
        for(int i=0;i<edges;i++){
            int u,v;
            cin>>u>>v;
            cin>>divshion[u][v];
        }
        table[0][1]=1.0;
        for(int i=0;i<time/10;i++){
            for(int j=1;j<=nodes;j++){
                if(table[i][j]>0){
                    for(int k=1;k<=nodes;k++)if(divshion[j][k]){
                        table[i+1][k]+=table[i][j]*divshion[j][k];
                    }
                }
            }
        }
        double ans=0.0;
        int loc;
        for(int i=0;i<time/10;i++){
            if(table[time/10][i]>ans){
                ans=table[time/10][i];
                loc=i+1;
            }
        }
        cout<<loc<<" "<<ans<<endl;

    }
    return 0;
}
