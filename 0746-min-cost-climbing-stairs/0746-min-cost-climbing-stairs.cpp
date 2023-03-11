int dp[1001];
class Solution {
public:
    int helper(vector<int>&cost, int i){
        if(i>=cost.size())
            return 0;
        if(i==cost.size()-1 || i==cost.size()-2)
            return cost[i];
        if(dp[i]!=-1)
            return dp[i];
        long long ans=INT_MAX;
        for(int j=1;j<3;j++){
            if(i+j<cost.size()){
                ans = min(ans,cost[i]*1LL+helper(cost,i+j));
            }
        }
        return dp[i] = ans;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int a = helper(cost,1);
        int b = helper(cost,0);
        return min(a,b);
    }
};