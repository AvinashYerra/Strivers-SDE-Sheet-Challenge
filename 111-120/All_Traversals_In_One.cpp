#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
vector<vector<int>>ans;
if(root==NULL) return ans;
     vector<int>pre;
    vector<int>ino;
    vector<int>post;
    stack<pair<BinaryTreeNode<int>*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        BinaryTreeNode<int> *node=st.top().first;
        int check=st.top().second;
        st.pop();
        if(check==1){
            pre.push_back(node->data);
            st.push({node,2});
            if(node->left!=NULL){
              st.push({node->left,1});
            }
        }else if(check==2){
            ino.push_back(node->data);
            st.push({node,3});
            if(node->right!=NULL){
              st.push({node->right,1});
            }
        }else{
            post.push_back(node->data);
        }
    }
    
    ans.push_back(ino);
     ans.push_back(pre);
      ans.push_back(post);
      return ans;

}