#include<stdio.h>

int main() {
    int T;
    int Case;
    int N, M, K;
    int Grid[202][22];
    int value[202];
    int result;
    int count;
    int zero;
    int i, j;
    freopen("input.txt", "r", stdin);
    freopen("output. txt", "w", stdout);
    scanf("%d", &T);
    for (Case=1; Case<=T; Case++) {
        scanf("%d %d %d", &N, &M, &K);
        for (i=0; i<N; i++) {
            value[i] = 0;
            for (j=0; j<M; j++) {
                scanf("%d", &Grid[i][j]);
                value[i] = (value[i]<<1) + Grid[i][j];
            }
        }
        result = 0;
        for (i=0; i<N; i++) {
            zero = 0;
            for (j=0; j<M; j++) if (0 == Grid[i][j]) zero++;
            if (K >= zero && (K-zero)%2 == 0) {
                count = 1;
                for (j=i+1; j<N; j++) if (value[i] == value[j]) count++;
                if (count > result)
                    result = count;
            }
        }
        printf("#%d %d\n", Case, result);
    }
    return 0;
}
