#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
   long long int t,n,g,p,k;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&g);
        k=(n*(g-1));
        if(g==2)k++;
        if(g!=1){
            p=ceil(log(k)/log(g))-1;
        }
        else p=n-1;
       printf("%lld\n",p-1);
    }
    return 0;
}
