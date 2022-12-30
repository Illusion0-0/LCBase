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
    int maxLvl = 0;
    vector<vector<int>>ans;
    unordered_map<int,vector<int>>m;
    
    void func(TreeNode *root, int lvl){
        if(!root)return;
        maxLvl = max(maxLvl,lvl);
        m[lvl].push_back(root->val);
        func(root->left,lvl+1);
        func(root->right,lvl+1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        func(root,0);
        for(int i=0;i<=maxLvl;i++){
            if(i%2!=0)reverse(m[i].begin(),m[i].end());
            ans.push_back(m[i]);
        }
        return ans;
    }
};