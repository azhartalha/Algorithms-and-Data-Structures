#include <bits/stdc++.h>
using namespace std;

/*
    The problem here is to find the total number of ways to reach (n-1, n-1) starting from (0, 0).
    Only two movements are allowed which are up(i+1, j) and right(i, j+1).
    However the catch is we can not move above the diagonal.
*/
long long int dp[1000][1000];

long long int underTheDiagonal(int n, int i, int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i==n-1 && j==n-1)
        return 1;

    dp[i][j] = 0;

    if(i<j)
        dp[i][j] += underTheDiagonal(n, i+1, j);

    if(j<n-1)
        dp[i][j] += underTheDiagonal(n, i, j+1);

    return dp[i][j];
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<1000; i++)
        for(int j=0; j<1000; j++)
            dp[i][j] = -1;

    printf("%lld", underTheDiagonal(n, 0, 0));
    return 0;
}
