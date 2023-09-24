/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int search(vector<int> &inorder, int target, int start, int end){
    for(int i=start;i<=end;i++){
        if(inorder[i] == target){
            return i;
        }
    }
}
TreeNode *util(vector<int> &preorder, vector<int> &inorder, int start, int end, int &index){
    if(start > end){
        return NULL;
    }
    int position = search(inorder,preorder[index],start,end);
    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    if(start == end){
        return root;
    }
    root->left = util(preorder,inorder,start,position-1,index);
    root->right = util(preorder,inorder,position+1,end,index);
    return root;
    
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int index =0;
    return util(preorder,inorder,0,inorder.size()-1,index);
}
