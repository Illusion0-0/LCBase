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
    
    void fun(TreeNode* root, vector<int>&temp){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)temp.push_back(root->val);
        fun(root->left,temp);
        fun(root->right,temp);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>one, two;
        fun(root1,one);
        fun(root2,two);
        return one==two;
    }
};