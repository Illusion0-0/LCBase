int dp[10005];
class Solution {
public:
    int rec(vector<int>&v, int i){
        if(i>=v.size())return false;
        if(i==v.size()-1)return true;
        if(dp[i]!=-1)return dp[i];
        bool ans = false;
        for(int j=1;j<=v[i];j++){
            ans = rec(v,i+j);
            if(ans)return dp[i+j] = true;
        }
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,0);
    }
};