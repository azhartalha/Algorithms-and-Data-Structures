#include<bits/stdc++.h>
using namespace std;

int matrix[1001][1001];
int r,c,rsum,csum;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        memset(matrix,0,sizeof(matrix[0][0])*r*c);
        int rowwise[r],columnwise[c];
        rsum=0;
        csum=0;
        for(int i=0; i<r; i++)
        {
            scanf("%d",rowwise+i);
            rsum+=rowwise[i];
        }
        for(int j=0; j<c; j++)
        {
            scanf("%d",columnwise+j);
            csum+=columnwise[j];
        }

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(rowwise[i] && columnwise[j])
                {
                    rowwise[i]--;
                    columnwise[j]--;
                }

            }
        }
        bool flag=true;
        int p=0,q=0;
        for(int i=0; i<r; i++)
        {
            p+=rowwise[i];
            if(p>1){
                flag=false;break;
            }
        }
        for(int j=0; j<c; j++)
        {
            q+=columnwise[j];
            if(q>1){
                flag=false;break;
            }
        }
        int k=p+q;
        if(flag && k<=1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}
