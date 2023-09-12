/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
     vector<vector<int>>ans;
    vector<int> temp;
    queue<TreeNode*> q;
    if(A == NULL){
        return ans;
    }
    q.push(A);
    q.push(NULL);
    // ans.push_back({A->val});
    while(q.size())
    {
        TreeNode* root=q.front();
        q.pop();
        if(root==NULL)
        {
            ans.push_back(temp);
            temp.clear();
            if(q.size())
            {
                q.push(NULL);
            }
        }
        else{
            temp.push_back(root->val);
            if(root->left)
            {
                q.push(root->left);
                // temp.push_back(root->left->val);
            }
            if(root->right)
            {
                q.push(root->right);
                // temp.push_back(root->right->val);
            }
        }
        
    }
    return ans;
}
