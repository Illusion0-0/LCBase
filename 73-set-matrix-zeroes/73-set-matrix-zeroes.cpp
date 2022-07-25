class Solution {
public:
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

};