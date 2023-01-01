/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*>s;
    
    void pushAllLeft(TreeNode *root){
        s.push(root);
        while(root->left){
            root=root->left;
            s.push(root);
        }
    }
    
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode *temp=NULL;
        if(hasNext()){
            temp=s.top();
            s.pop();
        }
        if(temp && temp->right)
            pushAllLeft(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */