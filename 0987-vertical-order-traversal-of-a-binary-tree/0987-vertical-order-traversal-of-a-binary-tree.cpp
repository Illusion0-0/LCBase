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
    int mi = INT_MAX, ma = INT_MIN;
    void func(TreeNode *root, int l, int a, map<int,map<int,vector<int>>>&ans){
        if(root==NULL)return;
        mi = min(mi,l);
        ma = max(ma,l);
        ans[l][a].push_back(root->val);
        func(root->left,l-1,a+1,ans);
        func(root->right,l+1,a+1,ans);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>ans;
        int l=0,a=0;
        vector<vector<int>>res;
        func(root,l,a,ans);
        for(int i=mi;i<=ma;i++){
            // vector<int>temp;
            vector<int>temp;
            for(auto j:ans[i]){
                sort(j.second.begin(),j.second.end());
                for(int k:j.second)temp.push_back(k);
            }
            res.push_back(temp);
        }
        return res;
    }
};