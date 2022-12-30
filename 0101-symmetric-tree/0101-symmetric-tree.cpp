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
    bool fun(TreeNode* a,TreeNode* b)
    {
        if(a==NULL || b==NULL)
        {
            return a==b;
        }
        return ((a->val==b->val)&&(fun(a->left,b->right))&&(fun(a->right,b->left)));
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL || root->right==NULL)
        {
            return root->left==root->right;
        }
        return fun(root->left,root->right);
    }
};