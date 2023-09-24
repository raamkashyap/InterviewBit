/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void util(TreeNode *root){
    if(root){
        TreeNode *node, *temp;
        temp = root->right;
        root->right = root->left;
        root->left = NULL;
        node = root;
        while(node->right){
            node = node->right;
        }
        node->right = temp;
        util(root->right);
    }
}
TreeNode* Solution::flatten(TreeNode* root) {
    util(root);
    return root;
}
