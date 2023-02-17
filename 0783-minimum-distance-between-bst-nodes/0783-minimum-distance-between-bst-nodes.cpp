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
    int ans=INT_MAX;
    vector<int>a;
    void dfs(TreeNode* root, TreeNode* parent){
        if(root==NULL)return;
        dfs(root->left,root);
        a.push_back(root->val);
        dfs(root->right,root);
    }
    
    int minDiffInBST(TreeNode* root) {
        dfs(root,NULL);
        sort(a.begin(),a.end()); // we don't need this as it's already inorder but it maked submission time faster LOL
        for(int i=0;i<a.size()-1;i++){
            ans=min(ans,abs(a[i]-a[i+1]));
        }
        return ans;
    }
};