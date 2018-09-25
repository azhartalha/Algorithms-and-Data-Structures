
#include <bits/stdc++.h>
using namespace std;

/*
    I have added problem statement as a PDF in the same director please have a look over it.

    To solve this problem I have come up with O(n^3) solution using Dynamic programming, where dp[i][j] denotes the
    best time in which the subarray arr[i:j] be removed.
*/


int mini(int a, int b)
{
    return (a<b)?a:b;
}

int solveInLeastTime(int arr[], int n)
{
    int dp[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            dp[i][j] = -1;
    }

    for(int i=0; i<n; i++)
        dp[i][i] =  1;

    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=n-i; j++)
        {
            int localMin = 501;

            for(int k=j; k<j+i-1; k++)
            {
                if(arr[k] == arr[j+i-1])
                    if(i == 2)
                    {
                        localMin = 1;
                    }
                    else
                    {
                        if(k==j)
                        {
                            localMin = dp[k+1][j+i-2];
                        }
                        else if(k==j+i-2)
                        {
                            localMin = mini(localMin, dp[j][k-1] + 1);
                        }
                        else
                        {
                            localMin = mini(localMin, dp[j][k-1] + dp[k+1][j+i-2]);
                        }
                    }
            }
            dp[j][j+i-1] = mini(mini(dp[j+1][j+i-1]+1 ,dp[j][j+i-2]+1), localMin);
        }
    }
    return dp[0][n-1];
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int a0=0; a0<T; a0++)
    {
        int n;
        scanf("%d", &n);

        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        printf("%d\n", solveInLeastTime(arr, n));
    }
    return 0;
}
