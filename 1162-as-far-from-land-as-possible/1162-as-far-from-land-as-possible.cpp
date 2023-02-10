class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        if(q.size()==n*n)return -1;
        int ans=-1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int>p = q.front();
                q.pop();
                int u = p.first;
                int v = p.second;
                for(int i=0;i<4;i++){
                    int ex = dx[i]+u, why = dy[i]+v; 
                    if(ex>=0 && ex<n && why>=0 && why<n && grid[ex][why]==0){
                        grid[ex][why]=1;
                        q.push({ex,why});
                    }    
                }
            }
            ans++;
        }
        return ans;
    }
};