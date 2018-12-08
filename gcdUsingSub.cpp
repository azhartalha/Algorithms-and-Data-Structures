#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(a>b)
        swap(a, b);
    while(a)
    {
        int tmp = a;
        a = b - a;
        b = tmp;
    }
    return b;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}
