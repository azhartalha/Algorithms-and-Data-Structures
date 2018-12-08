#include <bits/stdc++.h>
using namespace std;

long long int mod = 1000000007;
long long int GCD(long long int a, long long int b)
{
    //0printf("out %lld %lld\n", a, b);
    if(a>b)
    {
        swap(a, b);
        //printf("HI\n");
    }
    if(a==0)
        return b;
    while(a!=0)
    {
        //printf("%lld %lld\n", a, b);
        long long int tmp = a;
        a = b%a;
        b = tmp;
    }
    return b;
}

long long int custom_power(long long int A, long long int N)
{
    long long int pows[64];
    pows[0] = A%mod;
    for(int i=1; i<64; i++)
        pows[i] = (pows[i-1]*pows[i-1])%mod;
    long long int res = 1;
    int i=0;
    while(N)
    {
        if(N%2==1)
            res = (res*pows[i])%mod;
        N/=2;
        i++;
    }
    return res;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
    long long int A, B, N;
    scanf("%lld%lld%lld", &A, &B, &N);
    if(abs(A - B))
        {mod = abs(A - B);}
    printf("%lld\n", GCD((custom_power(A, N) + custom_power(B, N)), abs(A-B))%1000000007);
    mod = 1000000007;
    }
    return 0;
}
