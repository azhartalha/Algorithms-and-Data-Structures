
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;
long long int ronly,lonly,cnt;
struct BTNode
{
   int key;
   struct BTNode* left;
   struct BTNode* right;
};

typedef struct BTNode BTNode;

BTNode* getNewNode(int key)
{

    BTNode* temp = (BTNode*)malloc(sizeof(BTNode));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

pair < int, pair<int,int> > dfs(BTNode * root)
{
    pair<int,int> ret;
    int sz=0;
    ret.first=ret.second=0;
    if(root->left)
    {
        pair < int , pair <int,int> > q = dfs(root->left);
        pair <int,int> p = q.second;
        sz+=q.first;
        ret.first = 1+p.first;
        sz+=p.second;
    }
    if(root->right)
    {
        pair < int , pair <int,int> > q = dfs(root->right);
        pair <int,int> p = q.second;
        sz+=q.first;
        ret.second = 1+p.second;
        sz+=p.first;
    }
    lonly+=ret.first;
    ronly+=ret.second;
    cnt+=sz;
//    cout << root->key << " " << sz << endl;
    return make_pair(sz,ret);
}

//RETURN THE ANSWER FROM THE BELOW FUNCTION
long long countZigZagPaths(BTNode* root)
{
  ronly=lonly=0,cnt=0;
  dfs(root);
  return cnt;
}


