
#include <stdio.h>

int main()
{
    int n, i, j, k, l;
    int p[20], dp[20][20], cost;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions:\n");
    for(i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for(i = 1; i <= n; i++)
        dp[i][i] = 0;

    for(l = 2; l <= n; l++)
    {
        for(i = 1; i <= n-l+1; i++)
        {
            j = i + l - 1;
            dp[i][j] = 999999;

            for(k = i; k < j; k++)
            {
                cost = dp[i][k] + dp[k+1][j]
                       + p[i-1] * p[k] * p[j];

                if(cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum number of multiplications = %d",
           dp[1][n]);

    return 0;
}
