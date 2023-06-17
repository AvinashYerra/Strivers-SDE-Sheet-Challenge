#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int successor=-1,predecessor=-1;
    BinaryTreeNode<int>*curr=root;
    while(curr){
        if(key>=curr->data){
            curr=curr->right;
        }else{
            successor=curr->data;
            curr=curr->left;
        }
    }
     curr=root;
     while(curr){
         if(curr->data>=key){
             curr=curr->left;
         }else{
             predecessor=curr->data;
             curr=curr->right;
         }
     }
     return {predecessor,successor};
}
