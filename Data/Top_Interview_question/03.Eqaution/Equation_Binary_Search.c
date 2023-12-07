// X = A*N + B*log(N) + C*N*N*N;
// Input: A B C X
// Output: N
// 1 <= A <= 100
// 1 <= B <= 100
// 0 <= C <= 100
// 1 <= X <= 10^15
#include <stdio.h>
#include<limits.h>
#define MAX1 10000000000001
#define MAX2 100001
int T, Case;
int A, B, C;
long long X, Ans;
int Log(long long N)
{
    int value = 0;
    while (N >= 2.71828)
    {
        value++;
        N /= 2.71828;
    }
    return value;
}

long long answer(long long n){
    long long aa,bb,cc;
    aa = A*n;
    if(aa<0)return LLONG_MAX;
    bb = B*n;
    if(bb<0)return LLONG_MAX;
    bb *= Log(n);
    if(bb<0)return LLONG_MAX;
    cc = C*n*n*n;
    if(aa+bb+cc<0)return LLONG_MAX;
    return aa+bb+cc;

}

void find(long long X)
{
    long long start = 0, end = C ? MAX2 : MAX1;
    long long mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        //long long tmp = A * mid + B * log(mid) + mid * mid * mid * C;
        long long tmp = answer(mid);
        if (tmp == X)
        {
            Ans = mid;
            return;
        }
        else if (tmp > X)
            end = mid - 1;
        else
        {
           // Ans = mid;
            start = mid + 1;
        }
    }
}
int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (Case = 1; Case <= T; Case++)
    {
        
        scanf ("%d %d %d %lld", &A, &B, &C, &X);
        Ans=0;
        find(X);
        printf("#%d %lld\n", Case, Ans);
    }
    return 0;
}

