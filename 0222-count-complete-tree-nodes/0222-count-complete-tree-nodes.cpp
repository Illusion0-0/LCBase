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
class Solution {
public:
    int ans=0;
    
    int lheight(TreeNode* root){
        if(!root)return 0;
        int l = lheight(root->left);
        return 1+l;
    }
    
    int rheight(TreeNode* root){
        if(!root)return 0;
        int r = rheight(root->right);
        return 1+r;
    }
    
    void helper(TreeNode* root){
        if(!root)return;
        int l = lheight(root);
        int r = rheight(root);
        if(l==r) {ans+=(pow(2,l)-1);return;}
        else ans++;
        helper(root->left);
        helper(root->right);
    }
    
    int countNodes(TreeNode* root) {
        helper(root);
        return ans;
    }
};