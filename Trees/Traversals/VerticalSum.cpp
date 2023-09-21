/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::verticalSum(TreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    
    queue<pair<TreeNode*, int>> q;
    map<int,vector<int>> mp;
    
    q.push({root,0});
    
    while(!q.empty()){
        int dis = q.front().second;
        TreeNode *node  = q.front().first;
        q.pop();
        mp[dis].push_back(node->val);
        if(node->left) q.push({node->left,dis-1});
        if(node->right) q.push({node->right,dis+1});
    }
    for(auto x : mp){
        int sum = 0;
        for(auto v : x.second){
            sum += v;
        }
        res.push_back(sum);
    }
    return res;
}
