#include<stdio.h>
int visited[100],Set[100],Brust[100];
int N,Ans,A[100];

void inputcase(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&Set[i]);
        visited[i]=0;
    }
}
void print(){
    int score=0;
    for(int i=0;i<N;i++) Brust[i]=0;
    for(int i=0;i<N;i++){
        if(Brust[A[i]]!=-1){
            Brust[A[i]]=-1;
            int left=0,right=0,tmp=0;
            int ind=A[i];
            for(int j=ind-1;j>=0;j--){
                if(Brust[j]!=-1){
                  left=Set[j];
                  break;
                }
            }
            for(int j=ind+1;j<N;j++){
                if(Brust[j]!=-1){
                    right=Set[j];
                    break;
                }
            }
            if(left==0&&right==0) tmp=Set[A[i]];
            if(left!=0&&right!=0) tmp=left*right;
            if(left!=0&&right==0) tmp=left;
            if(left==0&&right!=0) tmp=right;
            score+=tmp;

        }
        if(score>Ans) Ans=score;
    }
}
void solve(int i){
    if(i==N){
        print();
        return;
    }
    for(int j=0;j<N;j++)if(0==visited[j]){
        visited[j]=1;
        A[i]=j;
        solve(i+1);
        visited[j]=0;
    }
}
void solvecase(){
    Ans=-1;
    solve(0);
    printf("%d\n",Ans);
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        inputcase();
        solvecase();
    }

    return 0;
}
