#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
void help(TreeNode<int>*root,vector<int>&ans){
    if(root==NULL) return ;
    help(root->left,ans);
    ans.push_back(root->data);
    help(root->right,ans);

}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    vector<int>ans;
    help(root,ans);
    return ans[k-1];
}