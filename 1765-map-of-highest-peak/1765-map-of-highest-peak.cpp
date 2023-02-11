class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    q.push({i,j}),grid[i][j]=-1;
            }
        }
        int sum=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int>p = q.front();
                q.pop();
                int u = p.first;
                int v = p.second;
                // grid[u][v]=-1;
                for(int i=0;i<4;i++){
                    int ex = dx[i]+u, why = dy[i]+v; 
                    if(ex>=0 && ex<n && why>=0 && why<m && grid[ex][why]==0){
                        grid[ex][why]=sum;
                        q.push({ex,why});
                    }    
                }
            }
            sum++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1)
                    grid[i][j]=0;
            }
        }
        return grid;
    }
};