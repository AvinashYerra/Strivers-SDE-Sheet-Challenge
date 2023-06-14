#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int height(BinaryTreeNode<int>*node,bool &ans){
    if(node==NULL) return 0;
    int lh=height(node->left,ans);
    int rh=height(node->right,ans);
    if(abs(lh-rh)>1) ans=false;
    return 1+max(lh,rh);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool ans=true;
     height(root,ans);
     return ans;
}