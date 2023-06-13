#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
     vector<int>ans;
     if(root==NULL) return ans;
    // Write your code here.
     map<int,int>nodes;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        TreeNode<int>*node=p.first;
        int x=p.second;
        if(nodes.find(x)==nodes.end()) nodes[x]=node->val;
        if(node->left!=NULL) q.push({node->left,x-1});
        if(node->right!=NULL) q.push({node->right,x+1}); 

    }
    
     for(auto it:nodes){
         ans.push_back(it.second);
     }

    return ans;
}