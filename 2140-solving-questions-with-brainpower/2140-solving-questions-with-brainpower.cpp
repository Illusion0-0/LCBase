long long dp[200005];
class Solution {
public:
    
    long long rec(vector<vector<int>>& q, int ind){
        if(ind>=q.size())return 0LL;
        if(ind==q.size()-1)return q[ind][0];
        if(dp[ind]!=0)return dp[ind];
        long long take = q[ind][0] + rec(q,ind+q[ind][1]+1);
        long long ntake = rec(q,ind+1);
        return dp[ind] = max(take,ntake);
    }
    
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        fill(dp,dp+2*n,0);
        return rec(q,0);
    }
};