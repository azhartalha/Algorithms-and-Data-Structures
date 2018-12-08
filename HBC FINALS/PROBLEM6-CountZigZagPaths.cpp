#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BTNode
{
   int key;
   struct BTNode* left;
   struct BTNode* right;
    
   long long leftAns;
   int leftSize;
   long long rightAns;
   int rightSize;
};

typedef struct BTNode BTNode;

BTNode* getNewNode(int key)
{

    BTNode* temp = (BTNode*)malloc(sizeof(BTNode));
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->leftAns=temp->rightAns = temp->leftSize = temp->rightSize = 0;
    return temp;
    
}



BTNode* insertInTree(BTNode* root, int key)
{
   if(root==NULL)
      return getNewNode(key);

   if(root->key > key)
        root->left= insertInTree(root->left,key);
    else root->right = insertInTree(root->right,key);
    return root;
}


long long ans = 0;

BTNode* countUtil(BTNode* root)
{
    if(!root)
        return NULL;

    BTNode* left = countUtil(root->left);
    BTNode* right = countUtil(root->right);
    if(left)
    {

        root->leftSize = left->leftSize + left->rightSize +1;
        root->leftAns = left->rightSize+left->leftAns;
       // cout<<"\nAt "<< root->key << " leftsize rightSize leftAns rightAns "<<root->leftSize <<" "<<root->leftAns<<endl;
        ans+=root->leftAns;
    }
    if(right)
    {
        root->rightSize = right->leftSize  + right->rightSize+1;
        root->rightAns = right->leftSize + right->rightAns;
        //cout<<"\nAt "<< root->key << " leftsize rightSize leftAns rightAns "<<root->rightSize <<" "<<root->rightAns<<endl;
        ans += root->rightAns;
    }
    //cout<<"\nAt "<< root->data << " leftsize rightSize leftAns rightAns "<<root->left
    return root;

}


long long countZigZagPaths(BTNode* root)
{
    ans=0;
    
    countUtil(root);
    //cout<<ans<<endl;
    return ans;
}
