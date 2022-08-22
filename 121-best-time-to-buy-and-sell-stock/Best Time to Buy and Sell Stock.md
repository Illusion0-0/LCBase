[Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

1. O(n^2) approach: simple implementation
2. O(n) approach: kind of tried in two-pointer style

```cpp
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
```

```text
Time Complexity: O(n)
Space Complexity: O(1)
```

3. Storing the minimum value in the left and subtract from every element in O(n) + keeping max diff.

```cpp
int maxProfit(vector<int>& prices) {
        int profit=0, mini=prices[0];
        for(int i=0;i<prices.size();i++){
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i]-mini);
        }
        return profit;
}
```

```text
Time Complexity: O(n)
Space Complexity: O(1)
```
