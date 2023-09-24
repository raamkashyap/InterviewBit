//based on bst property
TreeNode *util(vector<int> &preorder, int &index, int bound){
    if(index == preorder.size() || preorder[index] > bound){
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[index]);
    index++;
    root->left = util(preorder,index,root->val);
    root->right = util(preorder,index,bound);
    return root;
}
TreeNode* Solution::constructBST(vector<int> &preorder) {
    /*vector<int> inorder = preorder;
    sort(inorder.begin(),inorder.end());*/
    int index =0;
    return util(preorder,index,INT_MAX);
    
}