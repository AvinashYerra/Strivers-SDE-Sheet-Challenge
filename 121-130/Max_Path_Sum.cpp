#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int dfs(TreeNode<int>*root,long long int &maxi){
    if(root==NULL) return 0;
    long long int lh=max((long long int)0,dfs(root->left,maxi));
    long long int rh=max((long long int)0,dfs(root->right,maxi));
    maxi=max(maxi,root->val+lh+rh);
    return root->val+max(lh,rh);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL || root->left==NULL || root->right==NULL)  return -1;
    long long int maxi=1LL*INT_MIN;
    dfs(root,maxi);
    return maxi;
}