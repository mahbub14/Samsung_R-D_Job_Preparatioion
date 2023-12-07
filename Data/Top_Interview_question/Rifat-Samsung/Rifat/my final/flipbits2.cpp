#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    freopen("/home/rifat/Desktop/Samsung/ADVANCED (1)/FlipBits/Flip_bits_input.txt","r",stdin);
    cin>>test;
    for(int t=1;t<=test;t++){
        int n,m,k;
        cin>>n>>m>>k;
        int matrix[n][m];
        map<vector<int>,int> mp;

        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<m;j++){
                cin>>matrix[i][j];
                v.push_back(matrix[i][j]);
            }
            mp[v]++;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            vector<int> v;
            for(int j=0;j<m;j++){
                if(0 == matrix[i][j])
                    cnt++;
                v.push_back(matrix[i][j]);
            }
            if(k>=cnt && (k-cnt)%2 == 0)
                ans = max(ans,mp[v]);
        }

        cout<<t<<" # "<<ans<<endl;

    }

}
