/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool find(TreeNode *root,int x){
    if(root == NULL) return false;
    if(root->val == x) return true;
    if(find(root->left,x) || find(root->right,x)) return true;
    return false;
}
TreeNode* Util (TreeNode *root, int a, int b){
   if(root==NULL) return NULL;
   if(root->val == a){
       return root;
   }
   if(root->val == b){
       return root;
   }
   TreeNode *l = Util(root->left,a,b);
   TreeNode *r = Util(root->right,a,b);
   if(l && r) return root;
   if(l) return l;
   return r;
}
int Solution::lca(TreeNode* root, int B, int C) {
   if(find(root,B) && find(root,C)){
       return Util(root,B,C)->val;
   }
   return -1;
}
