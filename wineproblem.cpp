#include <bits/stdc++.h>
using namespace std;
int maxi(int a, int b)
{
    return (a>b)?a:b;
}
int bestAmount(const vector<int>& arr)
{
    int n = arr.size();
    int dp[n][n];
    for(int i=0; i<n; i++)
        dp[i][i] = arr[i]*n;

    for(int i=1; i<n; i++)
    {
        for(int j = 0; j<n-i; j++)
        {
            dp[j][j+i] = maxi(dp[j+1][j+i] + arr[j]*(n-i), dp[j][j+i-1] + arr[j+j]*(n-i));
            printf("%d %d %d\n", j, j+i, dp[j][j+i]);
        }
    }
    return dp[0][n-1];
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("best amount is %d", bestAmount(arr));
    return 0;
}
