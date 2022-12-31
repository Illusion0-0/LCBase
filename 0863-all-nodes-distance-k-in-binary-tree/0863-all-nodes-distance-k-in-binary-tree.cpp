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
    unordered_map<TreeNode*,TreeNode*>parent;
    vector<int>ans;
    bool found=false;
    unordered_map<TreeNode*,bool>vis;
    void markParents(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        while (!q.empty()) {
          int n = q.size();
          for (int i = 0; i < n; i++) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left), parent[temp->left]=temp;
            if (temp->right) q.push(temp->right), parent[temp->right]=temp;
          }
        }
    }
    
    void helper(TreeNode* root, TreeNode* target, int dist, int k){
        if(!root)return;
        if(root==target){found=true;dist=0;}
        if(found)vis[root]=true;
        if(found && dist==k)ans.push_back(root->val);
        if(found && parent[root] && !vis[parent[root]]) helper(parent[root],target,dist+1,k);
        if(!vis[root->left]) helper(root->left,target,dist+1,k);
        if(!vis[root->right]) helper(root->right,target,dist+1,k);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);
        helper(root,target,0,k);
        return ans;
    }
};