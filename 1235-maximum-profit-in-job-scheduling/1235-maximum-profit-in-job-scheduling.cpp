int dp[50001];
class Solution {
public:
    int helper(vector<vector<int>>&v, int ce, int i){
        if(i==v.size()){
            return 0;
        }
        if(v[i][0]<ce)
            return helper(v,ce,i+1);
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int ans=0;
        int take = v[i][2]+helper(v,v[i][1],i+1);
        int notake = helper(v,ce,i+1);
        
        return dp[i] = ans = max(take,notake);
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>v;
        for(int i=0;i<s.size();i++){
            v.push_back({s[i],e[i],p[i]});
        }
        sort(v.begin(),v.end());
        return helper(v,0,0);
    }
};