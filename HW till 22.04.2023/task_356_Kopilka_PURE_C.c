#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) 
{
    return a < b ? a : b;
}

int max(int a, int b) 
{
    return a > b ? a : b;
}

int main() {
    int E, F, N;
    scanf("%d %d %d", &E, &F, &N);

    int *p = malloc(N * sizeof(int));
    int *w = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) 
    {
        scanf("%d %d", &p[i], &w[i]);
    }

    const int INF = INT_MAX / 2;
    int *dp = malloc((F - E + 1) * sizeof(int));
    for (int i = 0; i <= F - E; i++)
    {
        dp[i] = INF;
    }
    dp[0] = 0;

    for (int i = 0; i < N; i++) 
    {
        for (int j = w[i]; j <= F - E; j++) 
        {
            dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
        }
    }

    if (dp[F - E] == INF) 
    {
        printf("This is impossible.\n");
    } else {
        printf("%d ", dp[F - E]);

        for (int i = 0; i <= F - E; i++) 
        {
            dp[i] = -INF;
        }
        dp[0] = 0;

        for (int i = 0; i < N; i++) 
        {
            for (int j = w[i]; j <= F - E; j++) 
            {
                dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
            }
        }
        printf("%d\n", dp[F - E]);
    }

    free(p);
    free(w);
    free(dp);

    return 0;
}
