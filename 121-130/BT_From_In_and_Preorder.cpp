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
TreeNode<int>*build(int prestart,int preend,int instart,int inend,vector<int>&inorder,vector<int>&preorder,map<int,int>&mp){
    if(instart>inend|| prestart>preend) return NULL;
    TreeNode<int>*root=new TreeNode<int>(preorder[prestart]);
    int inroot=mp[root->data];
    int nleft=inroot-instart;
    root->left=build(prestart+1,prestart+nleft,instart,inroot-1,inorder,preorder,mp);
    root->right=build(prestart+nleft+1,preend,inroot+1,inend,inorder,preorder,mp);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int n=inorder.size();
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    TreeNode<int>*root=build(0,n-1,0,n-1,inorder,preorder,mp);
    return root;
}
