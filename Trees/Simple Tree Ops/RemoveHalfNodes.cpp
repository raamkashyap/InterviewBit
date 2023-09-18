/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* root) {
    if(root == NULL) return NULL;
    if(!root->left && !root->right) return root;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if(!root->left || !root->right){
        return root->left? root->left : root->right;
    }
    return root;
}
