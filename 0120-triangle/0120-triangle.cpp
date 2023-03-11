int dp[201][201];
class Solution {
public:
    int helper(vector<vector<int>>& t, int i, int j){
        if(i==t.size() || j>=t[i].size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long ans = INT_MAX;
        ans = t[i][j]*1LL+helper(t, i+1,j);
        ans = min(ans,t[i][j]*1LL+helper(t, i+1,j+1));
        return dp[i][j] = ans;
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        memset(dp,-1,sizeof(dp));
        return helper(t, 0, 0);
    }
};