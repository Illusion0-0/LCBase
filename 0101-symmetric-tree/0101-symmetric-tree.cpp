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
    vector<int>arr;
    int lvl;
    unordered_map<int,vector<int>>m;
    void func(TreeNode *root, int l){
        if(!root){
            m[l].push_back(101);
            return;
        }
        m[l].push_back(root->val);
        lvl = max(lvl,l);
        func(root->left, l+1);
        func(root->right, l+1);
    }
    
    bool isSymmetric(TreeNode* root) {
        func(root,0);
        bool flag=true;
        for(int i=0;i<=lvl;i++){
            vector<int>temp = m[i];
            reverse(temp.begin(),temp.end());
            if(temp!=m[i]){
                flag=false;break;
            }
        }
        return flag;
    }
};