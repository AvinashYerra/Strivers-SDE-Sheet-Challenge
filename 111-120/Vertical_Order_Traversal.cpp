#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int,map<int,vector<int>>>nodes;
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        TreeNode<int>*node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].push_back(node->data);
        if(node->left!=NULL) q.push({node->left,{x-1,y+1}});
        if(node->right!=NULL) q.push({node->right,{x+1,y+1}});

    }
     vector<int>ans;
    for(auto row:nodes){
     //   vector<int>col;
        for(auto j:row.second){
           for(auto k:j.second){
               ans.push_back(k);
           }
        }
    }
    return ans;
}