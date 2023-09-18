/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode *root){
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
int Solution::isBalanced(TreeNode* root) {
    if(!root) return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh) >1 ) return 0;
    else return isBalanced(root->left) && isBalanced(root->right);
}
