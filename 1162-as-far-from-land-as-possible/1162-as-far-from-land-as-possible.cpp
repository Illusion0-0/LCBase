class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>>zero,one;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) zero.push_back({i,j});
                else one.push_back({i,j});
            }
        }
        int ans=-1;
        for(auto p:zero){
            int dist = INT_MAX;
            for(auto q:one){
                dist = min(dist,abs(q.first-p.first)+abs(q.second-p.second));
            }
            ans = max(ans,dist);
        }
        return (ans==INT_MAX?-1:ans);
    }
};