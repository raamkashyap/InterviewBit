/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int sum;
void helper(TreeNode *root, int sumToLeaf){
    if(!root) return;
    sumToLeaf *= 10;
    sumToLeaf += root->val;
    sumToLeaf %= 1003;
    if(root->left == NULL && root->right == NULL){
        sum += sumToLeaf;
        sum %= 1003;
        return;
    }
    helper(root->left,sumToLeaf);
    helper(root->right,sumToLeaf);
}
int Solution::sumNumbers(TreeNode* root) {
    sum =0;
    helper(root,0);
    return sum%1003;
    
}
