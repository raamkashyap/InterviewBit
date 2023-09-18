int Inorder(TreeNode* root, vector<int> &v, int B)
{
    if(root==NULL)return -1;
    Inorder(root->left,v,B);
    B--;
    if(B ==0) return root->val;
    v.push_back(root->val);
    Inorder(root->right,v,B);
}
int Solution::kthsmallest(TreeNode* a, int B) {
    vector<int> v;
    return Inorder(a,v,B);
}