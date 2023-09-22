int Solution::minDepth(TreeNode* root) {
if(!root) return 0;
    if(!root->left && !root->right) return 1;
    queue<pair<TreeNode*,int>> st;
    st.push({root,1});
    int res = INT_MAX;
    while(!st.empty()){
        TreeNode* val = st.front().first;
        int dis = st.front().second;
        if(!val->left && !val->right){
            res = min(res,dis);
        }
         st.pop();
        if(val->left){
            st.push({val->left,dis+1});
        }
        if(val->right){
            st.push({val->right,dis+1});
        }
    }
    return res;
}