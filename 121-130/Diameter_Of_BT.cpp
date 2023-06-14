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

int help(TreeNode<int>*node,int &maxi){
    if(node==NULL) return 0;
    int lh=help(node->left,maxi);
    int rh=help(node->right,maxi);
    maxi=max(maxi,lh+rh);
    
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int maxi=0;
    help(root,maxi);
    return maxi;

}
