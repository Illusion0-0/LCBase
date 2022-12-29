class Solution {
 public:
  int leftMost = INT_MAX, rightMost = INT_MIN, Maxlvl = 0;
  unordered_map<int, unordered_map<int, multiset<int>>> ans;
  // 2-D Map to store nodes at every [col][row] in sorted order
  void func(TreeNode* root, int col, int row) {
    if (root == NULL) return;
    leftMost = min(leftMost, col);
    rightMost = max(rightMost, col);
    Maxlvl = max(Maxlvl, row);
    ans[col][row].insert(root->val);
    func(root->left, col - 1, row + 1);
    func(root->right, col + 1, row + 1);
  }
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> res;
    func(root, 0, 0);
    for (int i = leftMost; i <= rightMost; i++) {
      vector<int> temp;
      for (int j = 0; j <= Maxlvl; j++) {
        for (int k : ans[i][j]) temp.push_back(k);
      }
      res.push_back(temp);
    }
    return res;
  }
};