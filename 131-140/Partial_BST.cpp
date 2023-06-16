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
bool help(BinaryTreeNode<int>*root,int leftbound,int rightbound){
    if(root==NULL) return true;
    if(root->data>rightbound || root->data<leftbound) return false;
    return help(root->left,leftbound,root->data) && help(root->right,root->data,rightbound);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return help(root,INT_MIN,INT_MAX);

}