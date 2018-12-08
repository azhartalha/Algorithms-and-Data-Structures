#include <cmath>
#include <cstdio>
#include<stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,k=3;
    cin >> t;
    k = t+1;
    while(k--){
        char str[10001];
        int p =0;
        char c;
        cin.getline(str,sizeof(str));
        //cout << str << endl;
        for(int i=0;str[i];++i){
            if(str[i] > '9' || str[i] < '0'){
                cout << str[i];
            }
            else{
                int t = i;
                int temp = 0;
                while(str[t] >='0' && str[t]<= '9'){
                    t++;
                    temp = temp*10 + (str[t-1]-'0');
                }
                if(str[t] != '+' && str[t] != '-' && str[t] != '*'){
                    cout << temp;
                    i = t-1;
                    continue;
                }
                else{
                    long long int j = i;
                    long long int a = 0, b = 0;
                    char op;
                    while(str[j] >= '0' && str[j] <='9'){
                        a = a*10 + (str[j]-'0');
                        ++j;
                    }
                    op = str[j++];
                    while(str[j] >= '0' && str[j] <='9'){
                        b = b*10 + (str[j]-'0');
                        ++j;
                    }
                    i = j - 1;
                    if(op == '+'){
                        cout << a+b ;
                    }
                    else if(op == '*')
                        cout << a*b ;
                    else
                        cout << a-b ;
                }
            }
            }
        if(k != t)
            cout << endl;
        }

    return 0;
}
