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
    vector<int>ans;
    
    void func(TreeNode *root){
        if(!root)return;
        func(root->left);
        ans.push_back(root->val);
        func(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        func(root);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            int ind = lower_bound(ans.begin(),ans.end(),k-ans[i])-ans.begin();
            if(ind!=ans.size() && ind!=i && ans[ind]+ans[i]==k)return true;
        }
        return false;
    }
};