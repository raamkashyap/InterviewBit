/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode *root, int B, int sum,bool &flag){
    if(!root) return;
    sum += root->val;
    if(!root->left && !root->right){
        if(sum == B){
            flag = true;
        }        
        return;
    }
    helper(root->left,B,sum,flag);
    helper(root->right,B,sum,flag);

}
int Solution::hasPathSum(TreeNode* root, int B) {
    bool flag = false;
    helper(root,B,0,flag);
    return flag;
}
