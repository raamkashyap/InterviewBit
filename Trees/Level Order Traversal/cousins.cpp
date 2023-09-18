/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    int parent = -1;
    while(q.size()){
        int n = q.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left->val == B && curr->left ){
                parent = curr->val;
                q.push(curr->left);
                v.push_back({curr->left->val, curr->val});
            }
            if(curr->right && curr->right->val == B){
                parent = curr->val;
                q.push(curr->right);
                v.push_back({curr->right->val, curr->val});
            }
        }
        /*int parent = -1;
        for(auto node:v){
            if(node.first == B){ 
                parent = node.second;
                break;
            }
        }*/
        if(parent != -1){
            for(auto node:v){
                if(node.second != parent){
                    res.push_back(node.first);
                }
            }
            return res;
        }
    }
    return res;
}
