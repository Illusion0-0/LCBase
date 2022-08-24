#### [Two Sum](https://leetcode.com/problems/two-sum/)

1. O(n^2) is strainght forward easy.

2. Better Approach using *lower_bound* in a sorted array

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res,temp=nums;
        vector<pair<int,int>>vp;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < temp.size(); i++)
        {
            vp.push_back({temp[i],i});
        }
        sort(vp.begin(),vp.end());
        
        for (int i = 0; i < nums.size(); i++)
        {
            int k = target - nums[i];
            int pos = lower_bound(nums.begin()+i+1,nums.end(),k)-nums.begin();
            if(pos<nums.size() && nums[pos]==k){
                res.push_back(vp[i].second);
                res.push_back(vp[pos].second);
                // cout<<nums[i]<<" "<<nums[pos]<<endl;
                return res;
            }
        }  
        return res;
}
```

```text
Time Complexity: O(n*log(n))
Space Complexity: O(n^2)
```
