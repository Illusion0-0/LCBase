class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        bool ans=false;
        for(int r=0;r<row;r++){
            if(binary_search(matrix[r].begin(),matrix[r].end(),target))ans=true;
        }
        return ans;
    }
};