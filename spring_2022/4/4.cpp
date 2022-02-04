#include <stdio.h>
#include <memory.h>

typedef unsigned long long ull;

bool check(int n, int m, int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

ull knightMoves(int n, int m)
{
    ull dp[n][m];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (check(n, m, i - 1, j - 2))
            {
                dp[i][j] += dp[i - 1][j - 2];
            }

            if (check(n, m, i - 2, j - 1))
            {
                dp[i][j] += dp[i - 2][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    printf("%llu", knightMoves(n, m));

    return 0;
}