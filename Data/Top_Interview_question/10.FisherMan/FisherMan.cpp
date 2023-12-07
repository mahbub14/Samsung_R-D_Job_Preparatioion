#include<stdio.h>
#include<math.h>
int N;
int Sit[61];
int Ans;
int used[3];
int gate[3];
int person[3];
void initSit() {
    int i;
    for (i=1; i<=N; i++)
        Sit[i] = 0;
}
int getLeft(int cur) {
    int i;
    for (i=cur; i>=1; i--) if (0 == Sit[i]) return i;
    return -N;
}
int getRight(int cur) {
    int i;
    for (i=cur+1; i<=N; i++) if (0 == Sit[i]) return i;
    return 2*N;
}
void fill(int g, int p) {
    int i, leftPos, rightPos, leftDis, rightDis;
    for (i=1; i<=p; i++) {
        leftPos = getLeft(g);
        rightPos = getRight(g);
        leftDis = g - leftPos;
        rightDis = rightPos - g;
        if (leftDis <= rightDis)
            Sit[leftPos] = g;
        else
            Sit[rightPos] = g;
    }
}
int checkLeft(int cur) {
    int i;
    for (i=cur; i>=1; i--) if (cur == Sit[i]) return i;
    return -N;
}
int checkRight(int cur) {
    int i;
    for (i=cur+1; i<=N; i++) if (cur == Sit[i]) return i;
    return 2*N;
}
void Remove(int g, int p) {
    int i, leftPos, rightPos, leftDis, rightDis;
    for (i=1; i<=p; i++) {
        leftPos = checkLeft(g);
        rightPos = checkRight(g);
        leftDis = g - leftPos;
        rightDis = rightPos - g;
        if (leftDis <= rightDis)
            Sit[leftPos] = 0;
        else
            Sit[rightPos] = 0;
    }
}
void print(){
    for(int i=1;i<=N;i++){
        printf("%d ",Sit[i]);
    }
    printf("\n");
}
void solve(int i) {
    int j;
    int leftPos, rightPos, leftDis, rightDis;
    if (i == 3) {
        int cost=0;
        for(int i=1;i<=N;i++) if (Sit[i] > 0) {
            cost+=abs(Sit[i] - i) + 1;
        }

        if(Ans>cost) Ans=cost;

       
        return;
    }
    for (j=0; j<3; j++) if (0 == used[j]) {
        used[j] = 1;

        fill(gate[j], person[j] - 1);

        leftPos = getLeft(gate[j]);
        rightPos = getRight(gate[j]);
        leftDis = gate[j] - leftPos;
        rightDis = rightPos - gate[j];
        if (leftDis < rightDis) {
            Sit[leftPos] = gate[j];
            solve(i+1);
            Sit[leftPos] = 0;
        }
        else if (leftDis > rightDis) {
            Sit[rightPos] = gate[j];
            solve(i+1);
            Sit[rightPos] = 0;
        }
        else {
            Sit[leftPos] = gate[j];
            solve(i+1);
            Sit[leftPos] = 0;
            Sit[rightPos] = gate[j];
            solve(i+1);
            Sit[rightPos] = 0;
        }
        Remove(gate[j], person[j] - 1);
        used[j] = 0;
    }
}
void inputcase(){
    scanf("%d",&N);
    for(int i=0;i<3;i++){
    scanf("%d%d",&gate[i],&person[i]);
    }


}
void solvecase(){
    Ans=999;
    initSit();
    solve(0);
    printf("%d\n",Ans);
}

int main(){
    int t;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        inputcase();
        solvecase();
    }
    return 0;
}
/**
Input:
5
10
4 5
6 2
10 2
10
8 5
9 1
10 2
24
15 3
20 4
23 7
39
17 8
30 5
31 9
60
57 12
31 19
38 16
Output:
18
25
57
86
339
**/
