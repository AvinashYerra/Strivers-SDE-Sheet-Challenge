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
bool help(TreeNode<int>*root,stack<TreeNode<int>*>&st,TreeNode<int>*leaf){
    if(!root) return false;
    st.push(root);
    if(leaf->data==root->data) return true;
    if(help(root->left,st,leaf) || help(root->right,st,leaf)) return true;
    st.pop();
    return false;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    if(root==NULL) return root;
    stack<TreeNode<int>*>st;
    bool f=help(root,st,leaf);
    TreeNode<int>*newroot=st.top();
    TreeNode<int>*parent=newroot;
    st.pop();
    while(!st.empty()){
        TreeNode<int>*curr=st.top();
        st.pop();
        if(curr->left==parent){
            curr->left=NULL;
            parent->left=curr;
        }else{
            curr->right=curr->left;
            curr->left=NULL;
            parent->left=curr;
       }
       parent=parent->left;
    }
    return newroot;
    
}
