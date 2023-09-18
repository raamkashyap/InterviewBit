/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
queue<int> q;
BSTIterator::BSTIterator(TreeNode *root) {
    if(root == NULL) return;
    BSTIterator(root->left);
    q.push(root->val);
    BSTIterator(root->right);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
 return q.size()>0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int temp = q.front();
    q.pop();
    return temp;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
