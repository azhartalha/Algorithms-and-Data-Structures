#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pows[31], n;
    pows[0] = 1;
    for(int i=1; i<31; i++)
        pows[i] = pows[i-1]*2;
    int T;
    scanf("%d", &T);
    while(T--){
    scanf("%d", &n);
    int minDif = INT_MAX;
    for(int i=0; i<31; i++)
    {
        for(int j=i+1; j<31; j++)
        {
            int diff = abs(n - (pows[i] + pows[j]));
            if(diff<minDif)
                minDif = diff;
        }
    }
    printf("%d\n",minDif);}
    return 0;
}
