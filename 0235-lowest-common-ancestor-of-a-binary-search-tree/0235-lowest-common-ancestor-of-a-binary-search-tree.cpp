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
    vector<int>a,b;
    
    bool fun1(TreeNode* root, TreeNode* p){
        if(root==NULL)return false;
        a.push_back(root->val);
        if(root==p)return true;
        if(fun1(root->left,p) || fun1(root->right,p))
            return true;
        a.pop_back();
        return false;
    }
    
    bool fun2(TreeNode* root, TreeNode* p){
        if(root==NULL)return false;
        b.push_back(root->val);
        if(root==p)return true;
        if(fun2(root->left,p) || fun2(root->right,p))
            return true;
        b.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun1(root,p);
        fun2(root,q);
        int i;
        for(i=0;i<min(a.size(),b.size());i++){
            if(a[i]!=b[i])break;
        }
        TreeNode *ans = new TreeNode(a[i-1]);
        return ans;
    }
};