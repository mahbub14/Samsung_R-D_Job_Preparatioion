#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;

        int matrix[n][m];
        int ans=0;
        map<vector<int>,int>mp;

        for(int i=0;i<n;i++)
        {
            vector<int>v;
            for(int j=0;j<m;j++)
            {
                cin>>matrix[i][j];
                v.push_back(matrix[i][j]);
            }

            mp[v]++;
        }
        for(int i=0;i<n;i++)
        {
            int  count_zero=0;

            vector<int>v;
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    count_zero++;
                }
                v.push_back(matrix[i][j]);
            }
            if(k>=count_zero&&(k-count_zero)%2==0)
            {
                ans=max(ans,mp[v]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
