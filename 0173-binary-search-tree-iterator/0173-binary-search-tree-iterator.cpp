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
    BSTIterator(TreeNode* root) {
        s.push(root);
        while(root->left){
            root=root->left;
            s.push(root);
        }
    }
    
    int next() {
        TreeNode *temp=NULL;
        int ans=0;
        if(hasNext()){
            temp=s.top();
            ans=temp->val;
            s.pop();
        }
        if(temp && temp->right){
          temp=temp->right;
            s.push(temp);
            while(temp->left){
                temp=temp->left;
                s.push(temp);
            }
        }
        return ans;
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