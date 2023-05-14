int dp[1001][1001];
class Solution {
public:
    
    int rec(string &p, string &q, int a, int b){
        if(a >= p.size() || b >= q.size())return 0;
        if(dp[a][b]!=-1)return dp[a][b];
        int len = 0, take = 0, ntake = 0;
        if(p[a]==q[b]){
            take = 1+rec(p,q,a+1,b+1);
        }
        else{
            ntake = max(rec(p,q,a+1,b),rec(p,q,a,b+1));
        }
        len = max(take,ntake);
        return dp[a][b] = len;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.size();
        int b = text2.size();
        memset(dp,-1,sizeof(dp));
        return rec(text1,text2,0,0);
    }
};