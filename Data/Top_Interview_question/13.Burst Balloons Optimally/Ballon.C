#include<stdio.h>
#define MAX 11
int Ballon[MAX], Visited[MAX];
int N, T, Case, Ans;
void readcase()
{
    int i;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &Ballon[i]);
        Visited[i]=0;
    }
}
void solve(int score)
{
    int i, j;
    int left, right;
    for(i = 0; i < N; i++) if (!Visited[i])
    {
        Visited[i] = 1;
        left = right = 0;
        for(j = i - 1; j >= 0; j--) if (!Visited[j])
        {
            left = Ballon[j];
            break;
        }
        for (j = i + 1; j < N; j++) if (!Visited[j])
        {
            right = Ballon[j];
            break;
        }
        if (left && right)
            solve(score + left * right);
        else if (left)
            solve(score + left);
        else if (right)
            solve(score + right);
        else if (score +Ballon[i]> Ans)
            Ans = score+Ballon[i];
        Visited[i] = 0;
    }
}
void solvecase()
{
    Ans = 0;
    solve(0);
}
void printcase()
{
    printf("#%d %d\n", Case, Ans);
}
int main()
{
    //freopen("Balloon_input", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d",&T);
    for(Case =1; Case <= T; Case++)
    {
        readcase();
        solvecase();
        printcase();
    }
    return 0;
}




