#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
int main() {
    ull k, q, n, x;
    ull ans=1;
    scanf("%llu", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%llu", &x);
        ans = (ans & x);
    }
    scanf("%llu", &q);
    while(q--){
        scanf("%llu", &x);
        printf("%s\n", (x & ans)==0?"YES":"NO");
    }
    return 0;
}
