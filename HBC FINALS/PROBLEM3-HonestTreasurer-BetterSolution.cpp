#include <stdio.h>
#include <string.h>

void printExpression(char str[])
{
    char s[100], tp[100];
    s[0] = 0;
    while(*str)
    {
        int x = sscanf(str, "%[^0-9]s", s);
        printf("%s", s);
        int a, b;
        char c;
        str = str+strlen(s);
        if(!*str)
            break;
        int r = sscanf(str, "%d %c %d", &a ,&c, &b);
        int t=0;
        if(r==3)
        {
            t = sprintf(tp, "%d%c%d", a, c, b);
            switch(c){
                case '+':
                    printf("%d", a+b); break;
                case '-':
                    printf("%d", a-b); break;
                case '*':
                    printf("%d", a*b); break;    
            }
        }
        else
            t = printf("%d", a);
        str = str + t;
    }
}

void getString(char s[]){
    fgets(s, 1000, stdin);
    char*p;
    if((p=strrchr(s,'\n')) != 0)
        *p = 0;
}
int main()
{
    int t;
    scanf("%d\n", &t);
    char str[1000], temp[20];
    while(t--){
       getString(str);
        printExpression(str);
        printf("\n");
    }    
    return 0;
}