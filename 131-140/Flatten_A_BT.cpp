#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void flatten(TreeNode<int>*node,TreeNode<int>*&prev){
    if(node==NULL) return ;
    flatten(node->right,prev);
    flatten(node->left,prev);
    node->right=prev;
    node->left=NULL;
    prev=node;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>*prev=NULL;
    flatten(root,prev);
    return root;
}