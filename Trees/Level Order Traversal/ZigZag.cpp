/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
     vector<vector<int>> levels;
    vector<int> currLevel;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    bool flag = true;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(flag == true){
                levels.push_back(currLevel);
                flag = false;    
            }
            else if(flag == false){
                reverse(currLevel.begin(),currLevel.end());
                levels.push_back(currLevel);
                flag = true;
            }
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
    return levels;
}
