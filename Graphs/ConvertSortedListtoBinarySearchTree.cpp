ListNode* findMid(ListNode* start, ListNode* end){
    ListNode* fast = start;
    ListNode* slow = start;
    while(fast != end && fast->next != end){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

TreeNode* addNode(ListNode* start,ListNode* end){

    if(start==NULL || start==end) return NULL;
    
    ListNode* mid = findMid( start, end);
    if(mid== end) return NULL;
    
    TreeNode *left = addNode(start, mid);
    TreeNode* t = new TreeNode(mid->val);
    TreeNode *right= addNode(mid->next, end);
    
    t->left = left;
    t->right= right;
    
    return t;

}


TreeNode* Solution::sortedListToBST(ListNode* A) {
    return addNode(A, NULL);

}