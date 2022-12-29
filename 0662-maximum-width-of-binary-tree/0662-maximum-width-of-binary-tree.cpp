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
    
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            long long minInd = q.front().second;
            long long s,e;
            for(int i=0;i<n;i++){
                long long curr = q.front().second-minInd;
                TreeNode *temp = q.front().first;
                q.pop();
                if(i==0)s=curr;
                if(i==n-1)e=curr;
                if(temp->left) q.push({temp->left,2*curr});
                if(temp->right) q.push({temp->right,2*curr+1});
            }
            ans = max(ans,e-s+1);
        }
        return ans;
    }
};