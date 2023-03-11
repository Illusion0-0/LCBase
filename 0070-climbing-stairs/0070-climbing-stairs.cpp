int dp[50];
class Solution {
public:
    int helper(int i, int n){
        if(i>=n)return 0;
        if(i==n-1)return 1;
        if(i==n-2)return 2;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        for(int j=1;j<3;j++){
            if(i+j<n){
                ans+=helper(i+j,n);
            }
        }
        return dp[i] = ans;
    }
    
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(0, n);
    }
};