int dp[10005];
class Solution {
public:
    
    int rec(vector<int>&v, int i){
        if(i==v.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = 1e5;
        for(int j=i+1;j<=min(i+v[i],(int)v.size()-1);j++){
            ans = min(ans,rec(v,j)+1);
        }
        return dp[i]=ans;
    }
    
    int jump(vector<int>& nums) {
        memset(dp,INT_MAX,sizeof(dp));
        return rec(nums,0);
    }
};