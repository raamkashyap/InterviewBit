/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* root) {
    queue<TreeLinkNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeLinkNode* curr = q.front();
        q.pop();
        if(curr != NULL){
            curr->next = q.front();    
        }
        
        if(curr == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}
