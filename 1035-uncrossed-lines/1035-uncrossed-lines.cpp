class Solution {
public:
    int dp[501][501];
    
    int rec(vector<int>& a, vector<int>& b, int i, int j){
        if(i>=a.size() || j>=b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int cnt=0;
        if(a[i]==b[j])
            cnt = 1+rec(a,b,i+1,j+1);
        else    
            cnt = max(rec(a,b,i+1,j),rec(a,b,i,j+1));
        return dp[i][j]=cnt;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return rec(nums1,nums2,0,0);
    }
};