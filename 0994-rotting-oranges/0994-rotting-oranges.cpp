class Solution {
public:
    int d[5]={-1,0,1,0,-1};
        
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans=-1, ok=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)ok++;
            }
        }
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int>p = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int a = p.first+d[i], b = p.second+d[i+1];
                    if(a >= 0 && b>=0 && a<n && b<m && grid[a][b]==1){
                        grid[a][b]=2, ok--,q.push({a,b});
                    }
                }
            }
            ans++;
        }
        if(ok)return -1;
        return (ans==-1?0:ans);
    }
};