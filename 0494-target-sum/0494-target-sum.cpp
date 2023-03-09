int dp[25][200005];
class Solution {
public:
    
    int helper(vector<int>& nums, int ind, int sum){
        if(ind==nums.size())return (sum==0);
        if(dp[ind][sum+100000]!=-1)return dp[ind][sum+100000];
        int ans=0;
        ans =(helper(nums,ind+1,sum+nums[ind]) + helper(nums,ind+1,sum-nums[ind]));
        return dp[ind][sum+100000]=ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(nums,0,target);
    }
};