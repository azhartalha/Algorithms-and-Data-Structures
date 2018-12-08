#include <bits/stdc++.h>
using namespace std;

long long int t,n,g;
/*
    First Crush

    This is a story of a boy shahrukh who had a secret crush on a girl kajol. As she was his first crush he was very nervous to tell the girl about his feelings.
    so he comes up with a very witty idea of creating a rumor about him self, which is, "kajol has a crush on shahrukh".
    He sent this message to X number of his classmates.
    Every time a person receives this message he/she forwards it another X members WHO DID NOT RECIVE THE MESSEGE UNTIL NOW AND ALSO ARE MEMBERS OF CLASS on the 10th second of receiving the message.
    There are a total of N students in the class, messages are being forwarded arbitrarily so shahrukh doesn't know when kajol might receive this message.
    shahrukh wants to find out what is the maximum time that might take for the message to reach kajol after he has sent the message to first X members, although shahrukh is very smart he is poor in doing math so it's time you write a program for him and help him!

    constraints:
        1 <= N <= 10^18
        1 <= X <= 10^18

    subtask: (30% of total sum weightage)
        1 <= N <= 10^9
        1 <= X <= 10^9
*/
int main()
{
    cin >> t;
    while(t--)
    {
        long long int x;
        scanf("%d %d",&n,&g);
        x=g;
        int tm=0,tot=1;
        if(g==1)
        {
            printf("%d\n",n-1);
            continue;
        }
        while(tot<n)
        {
            tm++;
            tot+=g;
            g*=x;
        }
       printf("%d\n",tm);
    }
    return 0;
}
