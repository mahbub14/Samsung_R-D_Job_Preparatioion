#include<bits/stdc++.h>
using namespace std;
int n, ans;

void solve(int row,int col,int issaferow,bool boomuse,int coin,vector<vector<int>> &grid){

    if(row<0 || col>=5 || col<0 ){
        ans = max(ans,coin);
        return;
    }
    if(grid[row][col] < 2){
        if(boomuse)
            issaferow--;
        coin += grid[row][col];
        //cout<<coin<<" "<<ans<<" "<<row<<" "<<col<<"  val = "<<grid[row][col]<<endl;
        row--;
        solve(row,col-1,issaferow,boomuse,coin,grid);
        solve(row,col,issaferow,boomuse,coin,grid);
        solve(row,col+1,issaferow,boomuse,coin,grid);
    }
    else{
        if(boomuse == 1 && issaferow<=0){
            ans = max(ans,coin);
            return;
        }
        else if (boomuse ==1 && issaferow>0){
            issaferow--;
        }
        else{
            boomuse = 1;
            issaferow = 4;
        }
        row--;
        solve(row,col-1,issaferow,boomuse,coin,grid);
        solve(row,col,issaferow,boomuse,coin,grid);
        solve(row,col+1,issaferow,boomuse,coin,grid);

    }
}

int main(){
    freopen("/home/rifat/Desktop/Samsung/Top_Interview_question (2)/Top_Interview_question/05.Aeroplane Bombing/SpaceShip_input.txt","r",stdin);
    int test;
    cin>>test;
    for(int t=1;t<=test;t++){
        ans = 0;
        cin>>n;
        vector<vector<int>> grid;

        int x;
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<5;j++){
                cin>>x;
                v.push_back(x);
            }
            grid.push_back(v);
        }

        int coin = 0;
        bool boomuse = 0;
        int row = n-1;
        int col = 2;
        int issaferow = 0;


        solve(row,col-1,issaferow,boomuse,coin,grid);
        solve(row,col,issaferow,boomuse,coin,grid);
        solve(row,col+1,issaferow,boomuse,coin,grid);
        printf("#%d %d\n",t,ans);




    }

}
