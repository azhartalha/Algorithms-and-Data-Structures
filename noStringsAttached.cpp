#include <bits/stdc++.h>
using namespace std;

int findOptimalX(int leftSweep[], int rightSweep[], int alphaIndex)
{
    int optimaization = 0, orginalCost = 0;

    for(int j=0; j<alphaIndex; j++)
        orginalCost+= leftSweep[j];

    for(int j=alphaIndex+1; j<26; j++)
        orginalCost+= rightSweep[j];

    for(int i=0; i<26; i++)
    {
        int cost = alphaIndex-i;

        if(cost<0)
            cost*=-1;

        for(int j=0; j<i; j++)
            cost+= leftSweep[j];
        for(int j=i+1; j<26; j++)
            cost+= rightSweep[j];
        if(cost < orginalCost)
        {
            optimaization = optimaization<orginalCost-cost? orginalCost-cost: optimaization;
        }
    }
    return optimaization;
}

int noStringsAttached(char S[], int n)
{
    int leftSweep[n][26], rightSweep[n][26];

    for(int j=0; j<26; j++)
    {
        leftSweep[0][j] = 0;
        rightSweep[n-1][j] = 0;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<26; j++)
            leftSweep[i][j] = leftSweep[i-1][j];
        leftSweep[i][S[i-1]-'a']++;
    }

    for(int i=n-2; i>=0; i--)
    {
        for(int j=0; j<26; j++)
            rightSweep[i][j] = rightSweep[i+1][j];
        rightSweep[i][S[i+1]-'a']++;
    }

    int Y = 0, bestOptimization = 0;
    for(int i=0; i<n; i++)
    {
        int runningSum = 0;
        for(int j=0; j<S[i]-'a'; j++)
            runningSum+=leftSweep[i][j];
        Y += runningSum;

        int optimization = findOptimalX(leftSweep[i], rightSweep[i], S[i]-'a');
        bestOptimization = optimization>bestOptimization? optimization: bestOptimization;
    }
    return Y-bestOptimization;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int a0=0; a0<T; a0++)
    {
        char S[100001];
        scanf("%s", S);
        printf("%d\n", noStringsAttached(S, strlen(S)));
    }
    return 0;
}
