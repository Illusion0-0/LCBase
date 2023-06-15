class Solution {
    int dp[305];
public:
    unordered_map<string,int>m;
    
    bool rec(string &s, int i){
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(m[temp]){
                if(rec(s,j+1))return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string c:wordDict)m[c]++;
        m[""]++;
        memset(dp,-1,sizeof(dp));
        return rec(s,0);
    }
};