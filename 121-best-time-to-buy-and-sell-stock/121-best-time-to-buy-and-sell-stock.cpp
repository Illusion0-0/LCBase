class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=0,high=1,ans=0,n = prices.size(),tl=-1,th=-1,chk=0;
        while(high<n){
            if(prices[low]<prices[high]){
            if(tl==-1)tl = low;
            else if(prices[low]<prices[tl])tl=low;
            if(prices[high]>prices[tl])th=high;
            ans = max(ans,prices[th]-prices[tl]);
            }
            low++,high++;
        }
        return ans;
    }
};