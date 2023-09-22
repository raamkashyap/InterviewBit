/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inOrder(TreeNode *root, vector<int> &res){
    if(!root) return;
    inOrder(root->left,res);
    res.push_back(root->val);
    inOrder(root->right,res);
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    // inOrder(A,res);
    stack<TreeNode *> st;
    TreeNode *curr = A;
    // st.push(curr)
    while(!st.empty() || curr){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        TreeNode *temp = st.top();
        st.pop();
        res.push_back(temp->val);
        curr = temp->right;
        
    }
    return res;
}
