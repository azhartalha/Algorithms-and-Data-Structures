#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int a0=0; a0<T; a0++)
    {
        int b = 0, o = 0, bo=0;
        char top[4], down[4];
        scanf("%s", top);
        scanf("%s", down);

        for(int i=0; i<3; i++)
        {
            if(top[i]=='b' && down[i]=='o' || top[i]=='o' && down[i]=='b')
                bo++;
            else if(top[i]=='b' || down[i]=='b')
                b++;
            else if(top[i]=='o' || down[i]=='o')
                o++;
        }

        if(b==3)
            printf("no\n");
        else if(o>1)
            printf("no\n");
        else if(b+o+bo==3)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
