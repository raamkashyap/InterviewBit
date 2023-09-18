/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve(TreeNode *root, int k, unordered_set<int> &st){

    if(!root)return false;

    if(st.find(k-root->val) != st.end()) return true;

    st.insert(root->val);

    return solve(root->left,k,st) or solve(root->right,k,st);

}


int Solution::t2Sum(TreeNode *root, int k) {

    unordered_set<int> st;

    return solve(root,k,st);

}
