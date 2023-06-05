#include<stdio.h>
int N,start_x,start_y,WH[6][6],used[100],A[100],min;
int end_x,end_y;
void print()
{
  int stop[2];
  int cost=0;
  stop[0]=start_x;
  stop[1]=start_y;

  for(int i=0;i<N;i++){
        int temp=0;
    if(A[i]==1){
        int temp1=abs(stop[0]-WH[i][0])+abs(stop[1]-WH[i][1]);
        int temp2=abs(stop[0]-WH[i][2])+abs(stop[1]-WH[i][3]);

        if(temp1<temp2){
            temp=temp1;
            stop[0]=WH[i][2];
            stop[1]=WH[i][3];
        }
        else{
            temp=temp2;
            stop[0]=WH[i][0];
            stop[1]=WH[i][1];
        }
        temp+=WH[i][4];
    }
    cost+=temp;
  }
  cost+=abs(stop[0]-end_x)+abs(stop[1]-end_y);
  if(cost<min) min=cost;

}

void solve(int i)
{
    if(i==N)
    {
        print();
        return;
    }
    A[i]=0;
    solve(i+1);
    A[i]=1;
    solve(i+1);
}

int main()
{
    int t;
    freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        scanf("%d%d",&start_x,&start_y);
        scanf("%d%d",&end_x,&end_y);
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<5; j++)
            {
                scanf("%d",&WH[i][j]);
            }
        }
        min=1e6;
        solve(0);
        printf("%d\n",min);
    }
    return 0;
}
