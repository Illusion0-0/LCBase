class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid ,vector<vector<bool>>&vis){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int ii=i+dx[k], jj=j+dy[k];
            if(ii>=0 && jj>=0 && ii<n && jj<m && !vis[ii][jj] && grid[ii][jj]=='1')
                dfs(ii,jj,n,m,grid,vis);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,n,m,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};