
/**
// same height of the tree so wrote solution using level order
int Solution::maxDepth(TreeNode* root) {
    if(!root) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1+ max(lh,rh);
}

 */
int Solution::maxDepth(TreeNode* root) {
    queue<pair<TreeNode*,int>> st;
    st.push({root,1});
    int dis = 0;
    while(!st.empty()){
        TreeNode* val = st.front().first;
         dis = st.front().second;
         st.pop();
        if(val->left){
            st.push({val->left,dis+1});
        }
        if(val->right){
            st.push({val->right,dis+1});
        }
    }
    return dis;
}
