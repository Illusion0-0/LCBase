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
// Space: O(n)
//     vector<int>ans;
//     void inorder(TreeNode* root){
//         if(root==NULL) return ;
//         inorder(root->left);
//         ans.push_back(root->val);
//         inorder(root->right);    
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         inorder(root);
//         return ans;
//     }
// Space: O(1) : Morris Traversal
       vector<int> inorderTraversal(TreeNode* root) {
           vector<int>inorder;
           while(root){
              if(root->left==NULL){
                  inorder.push_back(root->val);
                  root = root->right; 
              }
              else{
                  TreeNode *temp = root->left;
                  while(temp->right && temp->right!=root){
                      temp=temp->right;
                  }
                  if(temp->right==NULL){
                      temp->right=root;
                      root=root->left;
                  }
                  else{
                      temp->right=NULL;
                      inorder.push_back(root->val);
                      root=root->right;
                  }
              }
           }
           return inorder;
       }
};