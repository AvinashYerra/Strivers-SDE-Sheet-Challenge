#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>*help(vector<int>&preOrder,int &i,int bound){
    if(i==preOrder.size() || preOrder[i]>bound) return NULL;
    TreeNode<int>*root=new TreeNode<int>(preOrder[i++]);
    root->left=help(preOrder,i,root->data);
    root->right=help(preOrder,i,bound);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i=0;
    return help(preOrder,i,INT_MAX);
}