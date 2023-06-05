#include<stdio.h>
int N,A[100],Visited[100],Brust[100];
int Set[100];
int ans;
void print()
{

    int score=0;

    for(int i=0; i<N; i++) Brust[i]=0;

    for(int i=0; i<N; i++)
    {
        if(Brust[A[i]]!=-1)
        {
            int left=0;
            int right=0;
            int tmp=0;
            Brust[A[i]]=-1;
            //left
            for(int j=A[i]-1; j>=0; j--)
            {
                if(Brust[j]!=-1)
                {
                    left=Set[j];
                    break;
                }
            }
            //right
            for(int j=A[i]+1; j<N; j++)
            {
                if(Brust[j]!=-1)
                {
                    right=Set[j];
                    break;
                }
            }
            if(left==0&&right==0) tmp=Set[A[i]];
            else if(left>0&&right>0) tmp=left*right;
            else if(left>0&&right==0) tmp=left;
            else if(left==0&&right>0) tmp=right;
            score+=tmp;
        }

    }

    if(score>ans) ans=score;
    //printf("\n");
}

void solve(int i)
{
    if(i==N)
    {
        print();
        return;
    }
    for(int j=0; j<N; j++) if(Visited[j]==0)
        {
            A[i]=j;
            Visited[j]=1;
            solve(i+1);
            Visited[j]=0;
        }
}
int main()
{

    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&Set[i]);
    for(int i=0; i<N; i++)
    {
        Visited[i]=0;
    }
    ans=-1;
    solve(0);

    printf("%d\n",ans);
    return 0;
}
