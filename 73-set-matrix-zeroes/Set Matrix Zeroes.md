Link: https://leetcode.com/problems/set-matrix-zeroes/

**IMPLEMENTATION**

1. **First Approach**: store the entire (row & column) indexes if '0' is found and loop over row & column to set = 0. 

```cpp
void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int>row,column;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }
        for(int i=0;i<row.size();i++){
            for(int j=0;j<m;j++){
                matrix[row[i]][j]=0;
            }
            for(int j=0;j<n;j++){
                matrix[j][column[i]]=0;
            }
        }
        
    }

```

```text
Time Complexity: O(n*m)
Space Complexity: O(m+n)
```

2. **Follow Up Approach:** Setting the edge of a row/col = 0 where I find 0 at any index {basically using row[0] and col[0] as the 2 vectors used in first approach}

```cpp
void setZeroes(vector<vector<int>> &matrix)
    {
        int n=matrix.size(),m=matrix[0].size(),flag=0,r=0,c=0;
        if(matrix[0][0]==0)flag=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                    if(i==0 && matrix[0][0]==0)r=1;
                    if(j==0 && matrix[0][0]==0)c=1;
                }
            }
        }
        for(int i=1;i<n;i++)
        	if(matrix[i][0]==0)
        	for(int j=1;j<m;j++)
        		matrix[i][j]=0;
        for(int i=1;i<m;i++)
        	if(matrix[0][i]==0)
        	for(int j=1;j<n;j++)
        		matrix[j][i]=0;
        if(flag){
            for(int i=0;i<n;i++)matrix[i][0]=0;
            for(int i=0;i<m;i++)matrix[0][i]=0;
        }
        if(c)for(int i=0;i<n;i++)matrix[i][0]=0;
        if(r)for(int i=0;i<m;i++)matrix[0][i]=0;
        
    }
```

```text
Time Complexity: O(n*m)
Space Complexity: O(1)
```