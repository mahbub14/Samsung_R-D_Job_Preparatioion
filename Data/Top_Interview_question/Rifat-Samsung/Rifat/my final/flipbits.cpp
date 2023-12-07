#include<bits/stdc++.h>
using namespace std;

int main(){

    //freopen("/home/rifat/Desktop/Samsung/ADVANCED (1)/FlipBits/Flip_bits_input.txt","r",stdin);
    int test;
    int n,m,k,t=1;
    cin>>test;
    while(test--){
        cin>>n>>m>>k;
        int matrix[n][m];
        map<vector<int>,int> mp;

        // read data..........................
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<m;j++){
                cin>>matrix[i][j];
                v.push_back(matrix[i][j]);
            }
            mp[v] ++;
        }

        // Solve..............................
        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt_zero = 0;

            vector<int>v;
            for(int j=0;j<m;j++){
                if(0 == matrix[i][j]){
                    cnt_zero++;
                }
                v.push_back(matrix[i][j]);
            }
            if(k>= cnt_zero && (k-cnt_zero) %2 == 0){ // if minimum flip <=k then modify
                ans = max(ans,mp[v]);
            }
        }
        cout<<t++<<" # "<<ans<<endl;

    }

}

