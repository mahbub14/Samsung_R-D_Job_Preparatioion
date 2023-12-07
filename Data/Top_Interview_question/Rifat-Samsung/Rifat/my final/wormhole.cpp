#include<bits/stdc++.h>
using namespace std;
int matrix[35][5];
int visited[35];
int ans = INT_MAX;
int sx,sy,dx,dy;
int n;
void read_case(){


    cin>>sx>>sy;
    cin>>dx>>dy;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];
        }
    }
    memset(visited,0,sizeof visited);
    ans = INT_MAX;

}
int dist(int sx, int sy, int dx, int dy){

    return (abs(sx-dx)+abs(sy-dy));

}

void solve(int sx,int sy, int dx,int dy, int cost){
    ans = min(ans, dist(sx,sy,dx,dy) + cost);

    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            int tmp = dist(sx,sy,matrix[i][0],matrix[i][1]) + matrix[i][4] + cost;
            solve(matrix[i][2],matrix[i][3],dx,dy,tmp);

            tmp = dist(sx,sy,matrix[i][2],matrix[i][3]) + matrix[i][4] + cost;

            solve(matrix[i][0],matrix[i][1],dx,dy,tmp);
            visited[i] = 0;

        }
    }

}

int main(){

    freopen("/home/rifat/Desktop/Samsung/Top_Interview_question (2)/Top_Interview_question/08.Warmholes/Galaxy/Galaxy2_Input.txt","r",stdin);

    int test;
    cin>>test;

    for(int t=1;t<= test; t++){
        read_case();
        solve(sx,sy,dx,dy,0);
        cout<<t<<" "<<ans<<endl;


    }


}
