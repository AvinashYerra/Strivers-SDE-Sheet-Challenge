#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryBinaryTreeNode 
    {
    public : 
        T data;
        BinaryBinaryTreeNode<T> *left;
        BinaryBinaryTreeNode<T> *right;

        BinaryBinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
     vector<int>ans;
     if(root==NULL) return ans;

     map<int,int>nodes;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        BinaryTreeNode<int>*node=p.first;
        int x=p.second;
         nodes[x]=node->data;
        if(node->left!=NULL) q.push({node->left,x-1});
        if(node->right!=NULL) q.push({node->right,x+1}); 

    }
    
     for(auto it:nodes){
         ans.push_back(it.second);
     }

    return ans;
    
}
