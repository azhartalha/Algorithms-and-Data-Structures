vector<int> arr;
#define length size

bool check()
{
    int c1=0,c2=0;
    for(int i=0;i<arr.length();i++)
    {
        if(arr[i]%2==0)
        {
            c1++;
            i++;
            while(i<arr.length()&&arr[i]%2==0)
            {
                c1++;
                i++;
            }
        }
        if(c1)break;
    }
    for(int i=0;i<arr.length();i++)
    {
      //  cout << arr[i] << " ";
        c2+=(1-arr[i]%2);
    }
    //cout << endl;
    return c1==c2;
}

int noOfWaysToMakeL3(Node* head)
{
    long long int ans=0;
    vector <int> v;
    while(head)
    {
       // cout << head->data << endl;
        v.push_back(head->data);
        arr.push_back(head->data);
        head=head->next;
    }
    if(check())
        return -1;
    if(v.length()<3)
    {
        if(v.length()==1)
            return 2;
        return 4;
    }
    arr.clear();
    for(int i=0;i<v.length();i++)
    {
        for(int j=i+1;j<v.length();j++)
        {
            for(int k=j+1;k<v.length();k++)
            {
                for(int l=0;l<v.length();l++)
                {
                    if(l!=i&&l!=j&&l!=k)
                        arr.push_back(v[l]);
                }
                ans+=check();
                arr.clear();
            }
        }
    }
    for(int i=0;i<v.length();i++)
    {
        for(int j=i+1;j<v.length();j++)
        {
                for(int l=0;l<v.length();l++)
                {
                    if(l!=i&&l!=j)
                        arr.push_back(v[l]);
                }
                ans+=check();
            arr.clear();
        }
    }
    for(int i=0;i<v.length();i++)
    {

                for(int l=0;l<v.length();l++)
                {
                    if(l!=i)
                        arr.push_back(v[l]);
                }
                ans+=check();
        arr.clear();
    }
    return ans;
}

