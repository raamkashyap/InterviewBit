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
    vector<vector<int>> levels;
    vector<int> res;
    vector<int> currLevel;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr == NULL){
            levels.push_back(currLevel);
            if(!q.empty()){
                q.push(NULL);
                currLevel.clear();
            }
        }
        else{
            currLevel.push_back(curr->val);
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    for(int i=levels.size()-1;i>=0;i--){
        for(int j=0;j<levels[i].size();j++){
            res.push_back(levels[i][j]);
        }
    }
    return res;
}
