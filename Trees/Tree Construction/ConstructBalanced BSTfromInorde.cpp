/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *Util(const vector<int> &A, int start ,int end){
    if(start >end ){
        return NULL;
    }
    int mid = start + (end-start)/2;
    TreeNode *root = new TreeNode(A[mid]);
    root->left = Util(A,start,mid-1);
    root->right = Util(A,mid+1,end);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int start = 0;
    int end = A.size()-1;
    return Util(A, start ,end);
}
