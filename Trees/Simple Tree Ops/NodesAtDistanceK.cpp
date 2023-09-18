/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void numberOfNodes(TreeNode *A, int &n){
     if(A==NULL) return;
    numberOfNodes(A->left,n);
    n++;
    numberOfNodes(A->right,n);
}
vector<int> Solution::distanceK(TreeNode* root, int target, int k) {
    int n= 0;
    numberOfNodes(root,n);
    vector<int> adj[n+1];
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    adj[node->left->val].push_back(node->val);
                    adj[node->val].push_back(node->left->val);
                }
                if (node->right) {
                    q.push(node->right);
                    adj[node->right->val].push_back(node->val);
                    adj[node->val].push_back(node->right->val);
                }
            }
    }
    vector<int> res;
    queue<pair<int,int>> st;
    int vis[n+1] = {0};
    st.push({target,0});
    while (!st.empty() && k >= 0) {
        int u = st.front().first;
        int dis = st.front().second;
        st.pop();
        vis[u] = 1;
        if(dis == k){
            res.push_back(u);
        }
        for(auto v : adj[u]){
            if(!vis[v]){
                st.push({v,dis+1});
            }
        }
    }
    return res;   
}
