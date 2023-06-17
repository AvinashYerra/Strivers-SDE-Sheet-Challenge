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

class BSTiterator
{
    public:
    stack<TreeNode<int>*>st;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushall(root);
    }

    int next()
    {
        // write your code here
        auto temp=st.top();
        st.pop();
        pushall(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
    void pushall(TreeNode<int>*node){
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/