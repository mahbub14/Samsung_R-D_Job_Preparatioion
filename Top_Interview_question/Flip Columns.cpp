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
      int n,m;

      int ans=0;


    int k;
    cin>>n>>m>>k;
     int matrix[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>matrix[i][j];

        }


    }



    for(int i=0; i<n; i++)
    {
        int cout_zero=0;
        int row_count=0;
        int tmp[m];
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j]==0)
            {
                cout_zero++;

            }
            tmp[j]=matrix[i][j];
        }

        if(k>=cout_zero&&(k-cout_zero)%2==0)
        {


            for(int r=0; r<n; r++)
            {
                bool possible=true;
                for(int c=0; c<m&&&possible; c++)
                {
                    if(matrix[r][c]!=tmp[c])
                    {
                        possible=false;

                    }
                }
                if(possible) row_count++;
            }
            ans=max(ans,row_count);


        }

    }
    cout<<ans<<endl;
   }
}
