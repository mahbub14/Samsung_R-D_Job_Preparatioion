#include <stdio.h>
#define MAX 30
int g1, g2, g3;
int m1, m2, m3;
int T, Case, Ans;

void readcase()
{
    scanf("%d %d", &g1, &m1);
    scanf("%d %d", &g2, &m2);
    scanf("%d %d", &g3, &m3);
}
void solvecase()
{
    int i, j, k;
    int d1, d2, d3;
    int left, right, max;
    Ans = MAX;
    for (i = 1; i + m1 + m2 + m3 - 1 <= MAX; i++)
    {
        left = (g1 > i) ? g1 - i : i - g1;
        right = (g1 > i + m1 - 1) ? g1 - (i + m1 - 1) : (i + m1 - 1) - g1;
        d1 = (left > right) ? left : right;
        for (j = i + m1; j + m2 + m3 - 1 <= MAX; j++)
        {
            left = (g2 > j) ? g2 - j : j - g2;
            right = (g2 > j + m2 - 1) ? g2 - (j + m2 - 1) : (j + m2 - 1) - g2;
            d2 = (left > right) ? left : right;
            for (k = j + m2; k + m3 - 1 <= MAX; k++)
            {
                left = (g3 > k) ? g3 - k : k - g3;
                right = (g3 > k + m3 - 1) ? g3 - (k + m3 - 1) : (k + m3 - 1) - g3;
                d3 = (left > right) ? left : right;
                max = (d1 > d2) ? d1 : d2;
                max = (d3 > max) ? d3 : max;
                if (max < Ans)
                    Ans = max;
            }
        }
    }
}
void printcase()
{
     printf("#%d %d\n", Case, Ans);
}
int main()
{
    freopen("input.txt", "r", stdin);
    scanf ("%d", &T);
    for (Case = 1; Case <= T; Case++)
    {
        readcase();
        solvecase();
        printcase();
    }
    return 0;
}
