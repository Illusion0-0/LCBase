int dp[2600][2600];
class Solution {
public:
    
    int rec(vector<int>&v, int prev, int i){
        if(i>=v.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0, ntake=0;
        if(prev==-1 || v[prev]<v[i]) take = 1+rec(v,i,i+1);
        ntake = rec(v,prev,i+1);
        return dp[i][prev+1] = max(take,ntake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,-1,0);
    }
};