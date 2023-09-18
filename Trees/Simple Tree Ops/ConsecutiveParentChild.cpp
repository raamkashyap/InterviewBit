/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::consecutiveNodes(TreeNode* root) {
    int count =0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *t = q.front();
        q.pop();
        if(t->left){
            if(abs(t->left->val - t->val) == 1){
                count++;
            }
            q.push(t->left);
        }
        if(t->right){
            if(abs(t->right->val - t->val) == 1){
                count++;
            }
            q.push(t->right);
        }
    }
    return count;
}
