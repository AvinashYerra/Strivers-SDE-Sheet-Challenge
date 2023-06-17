#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void help(TreeNode<int>*root,vector<int>&ans){
    if(root==NULL) return ;
    help(root->left,ans);
    ans.push_back(root->data);
    help(root->right,ans);

}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int>ans;
    help(root,ans);
    int n=ans.size();
    if(k>n) return -1;
    return ans[n-k];
}
