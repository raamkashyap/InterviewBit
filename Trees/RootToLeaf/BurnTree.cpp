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
int Solution::solve(TreeNode* root, int B) {
     int n=0;
    numberOfNodes(root,n);
    map<int,vector<int>> adj;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *t = q.front();
        q.pop();
        if(t->left){
            q.push(t->left);
            adj[t->val].push_back(t->left->val);
            adj[t->left->val].push_back(t->val);
        }
        if(t->right){
            q.push(t->right);
            adj[t->val].push_back(t->right->val);
            adj[t->right->val].push_back(t->val);
        }
    }
    queue<pair<int,int>> st;
    st.push({B,0});
    map<int,int> vis;
    int res = INT_MIN;
    while(!st.empty()){
        int val = st.front().first;
        int dis = st.front().second;
        st.pop();
        res = max(res,dis);
        vis[val] = true;
        for(auto v : adj[val]){
            if(!vis[v]){
                st.push({v,dis+1});
            }
        }
    }
    return res;
}
