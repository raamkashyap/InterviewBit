/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *curr = A;
    while(!st.empty() || curr){
        while(curr != NULL){
            res.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        }
        TreeNode *temp = st.top();
        st.pop();
        // res.push_back(temp->val);
        curr = temp->right;
        
    }
    return res;
}
