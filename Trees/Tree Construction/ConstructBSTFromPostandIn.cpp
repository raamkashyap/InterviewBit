
//same as construct from in and pre but right hast to be constructed before left
 
int search(vector<int> &inorder, int target, int start, int end){
    for(int i=start;i<=end;i++){
        if(inorder[i] == target){
            return i;
        }
    }
}
TreeNode *util(vector<int> &postorder, vector<int> &inorder, int start, int end, int &index){
    if(start > end){
        return NULL;
    }
    int position = search(inorder,postorder[index],start,end);
    TreeNode* root = new TreeNode(postorder[index]);
    index--;
    if(start == end){
        return root;
    }
    root->right = util(postorder,inorder,position+1,end,index);
    root->left = util(postorder,inorder,start,position-1,index);
    
    return root;
    
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    if(inorder.size() != postorder.size()){
        return NULL;
    }
    int index =postorder.size()-1;
    return util(postorder,inorder,0,inorder.size()-1,index);
}
