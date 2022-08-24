class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low=0, high=rows*cols-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid/cols][mid%cols]==target)return true;
            if(matrix[mid/cols][mid%cols]<target) low = mid+1;
            else high = mid-1;
        }
        
        return false;
    }
};