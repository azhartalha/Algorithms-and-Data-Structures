#include <bits/stdc++.h>

long long int two_pow(int n)
{
    long long int res = 1;
    for(int i=0 ; i<n; i++)
        res*=2;
    return res;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int a0=0; a0<T; a0++)
    {
        int n, m, tmp, count=0;
        scanf("%d%d", &n, &m);
        for(int i = 0; i<n; i++)
        {
            scanf("%d", &tmp);
            if(tmp%m == 0)
                count++;
        }
        printf("%lld\n", two_pow(count)-1);
    }
    return 0;
}
