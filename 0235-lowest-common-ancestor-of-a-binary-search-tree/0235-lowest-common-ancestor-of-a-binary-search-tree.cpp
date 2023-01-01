/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans=NULL;
    
    void helper(TreeNode* root, int p, int q){
        if(!root)return;
        if(p<=root->val && q>=root->val){ans=root;return;}
        if(p<=root->val && q<=root->val) helper(root->left,p,q);
        if(p>root->val && q>root->val) helper(root->right,p,q);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, min(p->val,q->val), max(p->val,q->val));
        return ans;
    }
};