#include<bits/stdc++.h>
using namespace std;
int n,e,Time;



int main(){

    freopen("/home/rifat/Desktop/Samsung/Top_Interview_question (2)/Top_Interview_question/02.Doctor Probability/Probability_all_input.txt","r",stdin);

    int test;
    cin>>test;

    for(int t=1;t<= test;t++){
        cin>>n>>e>>Time;
        double div[100][100]= {0};
        double grid[100][100] = {0};
        int x,y;
        for(int i=0;i<e;i++){
            cin>>x>>y;
            cin>>div[x-1][y-1];
        }

        grid[0][0] = 1;

        for(int i=0;i< (Time/10);i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    for(int k=0;k<n;k++){
                        grid[i+1][k] += grid[i][j]*div[j][k];
                    }
                }
            }
        }

        double ans = 0;
        int f_node;
        for(int i=0;i<n;i++){
            if(grid[Time/10][i]>ans){
                ans = grid[Time/10][i];
                f_node = i;
            }
        }

        cout <<t<<" # "<<f_node+1 <<" "<< ans << endl;






    }

}
