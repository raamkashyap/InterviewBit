/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Helper(TreeNode *root, int  &ans){
    if(root == NULL){
        return 0;
    }
    int L = max(0,Helper(root->left,ans));
    int R = max(0,Helper(root->right,ans));
    ans = max(ans,root->val+L+R);
    return root->val + max(L,R);
}
int Solution::maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    Helper(root,ans);
    return ans;
}
