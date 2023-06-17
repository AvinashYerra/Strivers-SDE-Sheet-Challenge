#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
struct NodeValue{
  int max;
   int min;
   int size;
  NodeValue(int _min, int _max, int _size) {
    this->max = _max;
    this->min = _min;
    this->size = _size;
  }
}; 
NodeValue help(TreeNode<int> *root) {
  if (!root)
    return NodeValue(INT_MAX, INT_MIN, 0);
  auto left = help(root->left);
  auto right = help(root->right);
  if (left.max < root->data && root->data < right.min) {
    return NodeValue(min(root->data, left.min),
                     max(root->data, right.max),
                     1 + left.size + right.size);
  }
  return NodeValue(INT_MIN, INT_MAX, max(left.size, right.size));
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return help(root).size;

}
