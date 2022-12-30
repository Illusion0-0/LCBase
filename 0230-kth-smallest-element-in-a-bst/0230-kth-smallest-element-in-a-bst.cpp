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
    int c=0, ans=0;
    void func(TreeNode *root, int k){
        if(!root || c>k)return;
        func(root->left,k);
        c++;
        if(c==k){
            ans=root->val;
            return;
        }
        func(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        func(root,k);
        return ans;
    }
};