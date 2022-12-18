class Solution {
public:
    int dp[31];
    int fib(int n) {
        if(n<=1)return dp[n]=n;
        if(dp[n]) return dp[n];
        return dp[n]=fib(n-1)+fib(n-2);
    }
};