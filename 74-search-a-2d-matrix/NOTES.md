#### [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

1. Iterate over every row and apply **binary search** on it row[i];

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        bool ans=false;
        for(int r=0;r<row;r++){
            if(binary_search(matrix[r].begin(),matrix[r].end(),target))ans=true;
        }
        return ans;
}
```

```text
Time Complexity: O(n*log(n))
Space COmplexity: O(1)
```

2. Consider the matrix as a single array and apply binary search on the complete matrix. Little observation is ` matrix[mid/cols][mid%cols] `  

```cpp
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
```

```text
Time Complexity: O(log(mn))
Space Complexity: O(1)
```