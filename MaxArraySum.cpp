#include <bits/stdc++.h>
using namespace std;

/* Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset. */

long long int maxi(long long int a,long long int b,long long int c)
{
    if(a>b)
        return a>c?a:c;
    else
        return b>c?b:c;
}
long long int maxArraySum(int arr[], int n)
{
    if(n == 1)
        return arr[0];

    long long int dp1 = max(0, arr[0]), dp2 = maxi(0, dp1, arr[1]);

    for(int i=2; i<n; i++)
    {
        if(i%2 == 0)
        {
            dp1 = maxi(dp1, dp2, dp1 + arr[i]);
        }
        else
        {
            dp2 = maxi(dp2, dp1, dp2 + arr[i]);
        }
    }
    return max(dp1, dp2);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("%lld", maxArraySum(arr, n));
    return 0;
}
