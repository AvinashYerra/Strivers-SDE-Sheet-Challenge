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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
     vector<int>x;
     if(root==NULL) return x;
    vector<vector<int>>ans;
    bool flag=true;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>lvl;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int> *node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            lvl.push_back(node->data);
        }
        if(flag) {
            ans.push_back(lvl);
        }else{
            reverse(lvl.begin(),lvl.end());
            ans.push_back(lvl);
        }
        flag=!flag;
    }
   
    for(auto v:ans){
        for(auto i:v){
            x.push_back(i);
        }
    }
    return x;

}
