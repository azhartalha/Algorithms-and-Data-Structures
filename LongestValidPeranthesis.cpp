#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0)
            return 0;
        int dp[s.size()];
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                int maxi = 0;
                for(int j=0; j<i; j++)
                    if(dp[j]>maxi)
                        maxi = dp[j];
                dp[i] = maxi;
            }
            else
            {
                int maxi = 0;
                for(int j=0; j<i; j++)
                {
                    if(s[j]=='(' && dp[j]+2>maxi)
                    {
                        maxi = dp[j]+2;
                    }
                }
                dp[i]=maxi;
            }
        }
    int maxi = 0;
    for(int i =0; i<s.size(); i++)
        if(maxi<dp[i])
            maxi = dp[i];
    return maxi;
    }
};

int main()
{
    string s="()(())";
    Solution obj;
    printf("%d", obj.longestValidParentheses(s));
    return 0;
}
