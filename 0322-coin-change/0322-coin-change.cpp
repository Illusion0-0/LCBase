int dp[20][10005];

class Solution {
public:
    int res=-1;
    
    int helper(vector<int>&arr, int ind, int sumLeft){
        if(sumLeft<0)return INT_MAX-1;
        if(ind==arr.size())
            return (sumLeft==0)?0:INT_MAX-1;
        
        if(dp[ind][sumLeft]!=-1)
            return dp[ind][sumLeft];
        
        bool ans = false;
        int cnt = 0;
        if(arr[ind]>sumLeft){
            dp[ind][sumLeft] = cnt = 0 + helper(arr,ind+1,sumLeft);
        }
        else{
            int take = 1 + helper(arr,ind,sumLeft-arr[ind]);
            int notake = 0 + helper(arr,ind+1,sumLeft);
            cnt = min(take,notake);
        }
        
        return dp[ind][sumLeft]=res=cnt;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        helper(coins,0,amount);
        return (res==INT_MAX-1)?-1:res;
    }
};

/*class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>arr(amount+1,amount+1);
        arr[0]=0;
        for(int j:coins){
            for(int i=1;i<=amount;i++){
                if(i-j>=0)
                    arr[i] = min(arr[i],1+arr[i-j]);
            }
        }
        return arr[amount]!=amount+1?arr[amount]:-1;
    }
};*/