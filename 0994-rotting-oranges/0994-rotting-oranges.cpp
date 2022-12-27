class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int n=0, m=0, ans=-1, ok=0;
    bool isValid(int row, int col)
    {
        if (row < 0 || col < 0 || row >= n || col >= m)
            return false;
        return true;
    }
        
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
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
                    int a = p.first+dx[i];
                    int b = p.second+dy[i];
                    if(isValid(a,b) && grid[a][b]==1){
                        grid[a][b]=2, ok--;
                        q.push({a,b});
                    }
                }
            }
            ans++;
        }
        if(ok)return -1;
        return (ans==-1?0:ans);
    }
};