#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void help(BinaryTreeNode<int> *root,vector<int>&ans){
    if(root==NULL) return;
    help(root->left,ans);
    ans.push_back(root->data);
    help(root->right,ans);
}
bool finder(vector<int>&ans,int k){
    int i=0,j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==k){
            return true;
        }else if(ans[i]+ans[j]>k){
            j--;
        }else{
            i++;
        }
    }
    return false;
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int>ans;
    help(root,ans);
    return finder(ans,k);
}