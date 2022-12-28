class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        int n = s.size(), maxn=0, start=0, end=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n-i-1;j++)
            {
                if(i==0)
                {
                    dp[j][j+i+1] = (s[j]==s[j+i+1]);
                }   
                else
                {
                    dp[j][j+i+1] = ((s[j]==s[j+i+1]) && dp[j+1][j+i]);    
                }
                if(dp[j][j+i+1]){
                    int dist = i+1;
                    if(dist>maxn){
                        maxn=dist;
                        start=j;
                        end=j+i+1;
                    }
                }
            }
        }
        string res="";
        for(int i=start;i<=end;i++){
            res+=s[i];
        }
        return res;
    }
};