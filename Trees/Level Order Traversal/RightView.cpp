/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    res.push_back(root->val);
    if(root->left == NULL && root->right == NULL) return res;
    q.push(NULL);
    while(!q.empty()){
        TreeNode *curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                res.push_back(q.front()->val);
                q.push(NULL);
            }
        }
        else{
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);    
        }
        
    }
    return res;
}
