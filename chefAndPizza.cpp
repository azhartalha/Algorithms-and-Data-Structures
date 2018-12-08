#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

vector<long long int> factors(long long int n)
{
    vector<long long int> res;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            res.push_back(i);
        }
    }
    int len = res.size();
    for(int i=0; i<len; i++)
    {
        if(n/res[len - i -1] != i)
            res.push_back(n/res[len - i -1]);
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long int n;
        scanf("%lld", &n);
        vector<long long int> n_factors = factors(n);
        long long int res = 0;
        for(int i=0; i<n_factors.size(); i++)
        {
            if(i >= 1)
                res = (res + (n_factors[i] - n_factors[i-1] - 1)*(n/n_factors[i]))%mod;
            res = (res+(n/n_factors[i]))%mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}
