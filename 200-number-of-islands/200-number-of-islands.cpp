class Solution {
public:
    // BFS
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        int cnt=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    vis[i][j]=true;
                    q.push({i,j});
                    cnt++;
                    while(!q.empty()){
                        pair<int,int>p = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int ii=p.first+dx[k], jj=p.second+dy[k];
                            if(ii>=0 && jj>=0 && ii<n && jj<m && !vis[ii][jj] && grid[ii][jj]=='1'){
                                vis[ii][jj]=true;
                                q.push({ii,jj});
                            }
                                
                        }
                    }
                }
            }
        }
        return cnt;
        
    }
};