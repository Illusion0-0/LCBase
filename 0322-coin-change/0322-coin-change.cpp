class Solution {
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
};