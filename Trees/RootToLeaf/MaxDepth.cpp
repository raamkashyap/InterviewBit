/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
