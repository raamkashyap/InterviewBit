/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int k) {
    unordered_map<int,int>mp; 
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    mp[root->val] = -1;
    while(!q.empty()){
        TreeNode *curr = q.front();
        q.pop();
        if(curr->left){
            mp[curr->left->val] = curr->val;
            q.push(curr->left);
        }
        if(curr->right){
            mp[curr->right->val] = curr->val;
            q.push(curr->right);
        }
    }
    int temp = k;
    while(mp.find(temp) != mp.end()){
        res.push_back(temp);
        temp = mp[temp];
    }
    reverse(res.begin(),res.end());
    return res;
}
