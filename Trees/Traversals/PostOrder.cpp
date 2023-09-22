/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    if(A == NULL) return res;
    stack<TreeNode *> st;
    TreeNode *curr = A;
    st.push(curr);
    while(!st.empty()){
        TreeNode *curr = st.top();
        st.pop();
        res.push_back(curr->val);
        if(curr->left != NULL){
            st.push(curr->left);
        }
        if(curr->right){
            st.push(curr->right);
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
