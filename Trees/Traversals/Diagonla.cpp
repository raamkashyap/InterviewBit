/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
map<int,vector<int>> mp;
void preorder(TreeNode *root, int dia){
    if(!root) return;
    mp[dia].push_back(root->val);
    preorder(root->left,dia+1);
    preorder(root->right,dia);
    
}
vector<int> Solution::solve(TreeNode* root) {
    vector<int> res;
    mp.clear();
    if(root == NULL) return res;
    preorder(root,0);
    
    for(auto x : mp){
        for(auto ele : x.second)
        {
            res.push_back(ele);
        }
    }
    return res;
}
