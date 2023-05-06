#include<bits/stdc++.h>

using namespace std;

int main()
{
   /// freopen("input.txt","r",stdin);
    int n;
    int g1,g2,g3;
    int p1,p2,p3;
    cin>>n;
    cin>>g1>>g2>>g3;
    cin>>p1>>p2>>p3;

    int ans=1e9;

    for(int i=1; i+p1+p2+p3-1<=n; i++)
    {

        ///cout<<"Gate 1: "<<i<<" "<<i+p1-1<<endl;

        for(int j=i+p1; j+p2+p3-1<=n; j++)
        {


            for(int k=j+p2; k+p3-1<=n; k++)
            {


                int cost=0;
                for(int t=i; t<i+p1; t++)
                {
                    cost+=abs(g1-t)+1;
                }
               /// cout<<"Gate 1 Cost :"<<cost<<endl;

                for(int t=j; t<j+p2; t++)
                {
                    cost+=abs(g2-t)+1;
                }
                ///cout<<"Gate 2 Cost :"<<cost<<endl;
                for(int t=k; t<k+p3; t++)
                {
                    cost+=abs(g3-t)+1;
                }
                ///cout<<"Gate 3 Cost :"<<cost<<endl;
         ans=min(cost,ans);
            }


        }




    }
    cout<<ans<<endl;




    return 0;
}
