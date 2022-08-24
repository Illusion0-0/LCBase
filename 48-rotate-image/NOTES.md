[Rotate Image](https://leetcode.com/problems/rotate-image/)

1. Create another matrix and putting row[0] in col[n-1], row[1] in col[n-1-1] ..... 

```text
Time Complexity: O(n^2)
Space Complexity: O(n^2)
```

2. **Observation Approach**: Transpose the matrix and reverse each row

```cpp
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r=0;r<n;r++){
            for(int c=r+1;c<n;c++){
                swap(matrix[r][c],matrix[c][r]);                
            }
        }
        for(int r=0;r<n;r++){
            reverse(matrix[r].begin(),matrix[r].end());
        }
}
```

```text
Time Complexity: O(n^2)
Space Complexity: O(1)
```

3. Can also be done using clockwise cyclic shiting. 