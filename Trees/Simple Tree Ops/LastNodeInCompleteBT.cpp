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
int Solution::lastNode(TreeNode* root) {
    if(!root->left && !root->right) return root->val;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh > rh){
        return lastNode(root->left);
    }
    return lastNode(root->right);
}
