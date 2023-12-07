#include<bits/stdc++.h>
using namespace std;
int n;
int g1,g2,g3;
int gp1,gp2,gp3;

int ans;
void read_case1(){
    cin>>n;
    cin>>g1>>g2>>g3;
    cin>>gp1>>gp2>>gp3;
}

void read_case2(){
    cin>>n;
    cin>>g1>>gp1;
    cin>>g2>>gp2;
    cin>>g3>>gp3;


}

void solve(){

    for(int i=1;i<= n-gp2-gp3;i++){
        for(int j= i + gp1;j<=n-gp3;j++){
            for(int k = j+gp2; k<=n;k++){
                int c = 0;

                for(int p=i;p<i+gp1;p++){
                    c += abs(p-g1);
                }
                for(int p=j;p<j+gp2;p++){
                    c += abs(p-g2);
                }
                for(int p=k;p<k+gp3;p++){
                    c += abs(p-g3);
                }
                c += gp1+gp2+gp3;
                ans = min(c,ans);

            }
        }
    }


}

int main(){
    int test;
    cin>>test;
    for(int t=1;t<=test;t++){
        //read_case1();
        read_case2();
        ans = INT_MAX;
        solve();
        cout<<ans<<endl;


    }


}


