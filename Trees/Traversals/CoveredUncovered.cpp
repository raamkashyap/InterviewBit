/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long Solution::coveredNodes(TreeNode* root){
    queue<TreeNode *> q;
    q.push(root);
    long cover = 0;
    long uncover = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode *temp = q.front();
            q.pop();
            if(i==0 || i == size-1){
                uncover += temp->val;
            }
            else cover += temp->val;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }        
    }
    return abs(cover-uncover);
}
