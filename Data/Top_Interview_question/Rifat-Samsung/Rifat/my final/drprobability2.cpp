#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("/home/rifat/Desktop/Samsung/Top_Interview_question (2)/Top_Interview_question/02.Doctor Probability/Probability_all_input.txt","r",stdin);

    int test;

    cin>>test;

    for(int t=1;t<=test;t++){
        int n,e,Time;
        cin>>n>>e>>Time;
        int x,y;
        double division[100][100]={0};
        double table[100][100]={0};

        for(int i=0;i<e;i++){
            cin>>x>>y;
            cin>>division[x-1][y-1];
        }

        table[0][0] = 1;
        for(int i=0;i<(Time/10);i++){
            for(int j=0;j<n;j++){
                if(table[i][j]>0){
                    for(int k = 0;k<n;k++){
                        table[i+1][k] += table[i][j] * division[j][k];
                    }
                }
            }
        }

        double  ans = 0;
        int f_node ;

        for(int i=0;i<n;i++){
            if(table[Time/10][i]> ans){
                ans =table[Time/10][i];
                f_node = i+1;
            }
        }


        cout <<t<<" # "<<f_node <<" "<< ans << endl;
    }

}
