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
    // Time: O(h)
    // Space: O(h)
    stack<TreeNode*>s;
    bool rev=true;
    void pushAllLeft(TreeNode *root){
        while(root){
            s.push(root);
            if(rev)root=root->right;
            else root=root->left;
        }
    }
    
    BSTIterator(TreeNode* root, bool r) {
        rev=r;
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode *temp=NULL;
        if(hasNext()){
            temp=s.top();
            s.pop();
        }
        if(!rev)
            pushAllLeft(temp->right);
        else 
            pushAllLeft(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};


class Solution {
public:
    // unordered_set<int> s;
    // bool findTarget(TreeNode* root, int k) {
    //     if (!root) return false;
    //     if (s.count(k - root->val)) return true;
    //     s.insert(root->val);
    //     return findTarget(root->left, k) || findTarget(root->right, k);
    // }
    bool findTarget(TreeNode* root, int k){
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next(), j = r.next();
        while(i<j){
            int sum = i+j;
            if(sum==k)return true;
            else if(sum<k)i=l.next();
            else j=r.next();
        }
        return false;
    }
};