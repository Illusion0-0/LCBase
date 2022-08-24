[Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

1. Sort and check (i & i+1)

```cpp
int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==0)return nums[i];
        }
        return nums[0];
}
```

```text
Time Complexity: O(n*logn)
Space Complexity: O(1)
```

2. map<int,int> can be used as well

3. If there is a number repeated in a permutation array then a loop will definitely form.

```cpp
int findDuplicate(vector<int>& nums) {
        int k = 0, ans=0;
        while(1){
            nums[k]*=-1;
            ans=k;
            k = -1*nums[k];
            if(k<0)break;
        }
        for(int i:nums)if(i<0)i*=-1;
        return ans;
}
```

```text
Time Complexity: O(n)
Space Complexity: O(1)
```

4. Above approach is not very efficient for negative numbers, better approach is using **fast & slow pointer**.

