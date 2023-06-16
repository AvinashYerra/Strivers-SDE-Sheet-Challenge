/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>*build(int instart,int inend,int poststart,int postend,vector<int>&inOrder,vector<int>&postOrder,map<int,int>&mp){
     if(instart>inend || poststart>postend) return NULL;
     TreeNode<int>*root=new TreeNode<int>(postOrder[postend]);
     int inroot=mp[root->data];
     int inleft=inroot-instart;
    root->left=build(instart,inroot-1,poststart,poststart+inleft-1,inOrder,postOrder,mp);
    root->right=build(inroot+1,inend,poststart+inleft,postend-1,inOrder,postOrder,mp);
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     if(inOrder.size()!=postOrder.size()) return NULL;
     map<int,int>mp;
     int n=inOrder.size();
     for(int i=0;i<n;i++){
          mp[inOrder[i]]=i;
     }
     TreeNode<int>*root=build(0,n-1,0,n-1,inOrder,postOrder,mp);
     return root;
}
