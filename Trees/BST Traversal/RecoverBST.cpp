/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void Inorder(TreeNode *root, TreeNode* &first, TreeNode* &middle, TreeNode* &last, TreeNode* &prev){
    if(!root) return;
    Inorder(root->left,first,middle,last,prev);
    if(prev != NULL && root->val < prev->val){
        if(first == NULL){
            first = prev;
            middle = root;
        }
        else
            last = root;
    }
    prev = root;
    Inorder(root->right,first,middle,last,prev);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode *first = NULL;
    TreeNode *middle = NULL;
    TreeNode *last = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);
    Inorder(A,first,middle,last,prev);
    if(last) {
        return {last->val, first->val};
    }
    else {
        return {middle->val, first->val,};
    }
}

