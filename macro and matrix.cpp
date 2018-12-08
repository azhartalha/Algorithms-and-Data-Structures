#include <cstdio>
#include <iostream>
using namespace std;

int mini(int a, int b, int c)
{
    if(a<b)
        if(a<c)
            return a;
        else
            return c;
    else
        if(b<c)
            return b;
        else
            return c;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int a0=0; a0<T; a0++)
    {
        int n;
        scanf("%d", &n);

        int matrix[n][n];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &matrix[i][j]);

        int dp[n][n], vertical[n], horizontal[n];

        for(int i=0; i<n; i++)
        {
            dp[i][0] = 1;
            vertical[i] = 1;
        }

        for(int i=0; i<n; i++)
        {
            dp[0][i] = 1;
            horizontal[i] = 1;
        }
        int maxi = 1;
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j] == matrix[i-1][j-1] && matrix[i][j] == matrix[i-1][j] && matrix[i][j] == matrix[i][j-1])
                {
                    dp[i][j] = mini(dp[i-1][j-1], vertical[j], horizontal[i]) + 1;
                    vertical[j] += 1;
                    horizontal[i] += 1;

                    if(dp[i][j] > maxi)
                        maxi = dp[i][j];
                }
                else
                {
                    dp[i][j] = 1;

                    if(matrix[i][j] == matrix[i-1][j])
                    {
                        vertical[j] += 1;
                    }
                    else
                    {
                        vertical[j] = 1;
                    }

                    if(matrix[i][j] == matrix[i][j-1])
                    {
                        horizontal[i] += 1;
                    }
                    else
                    {
                        horizontal[i] = 1;
                    }
                }
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}
