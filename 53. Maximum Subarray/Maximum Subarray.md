[Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

1. O(n^3) approach for i , j and k --> (i.....j) for adding elements from i...j
2. O(n^2) approach for i , j and keeping sum += nums[j] and updating max;
3. **Kadane's Algorithm:** Taking max = nums[0] and updating max with new sum + set sum = 0 if sum becomes negative because considering -ve will decrease the sum which we don't want.

```cpp
int maxSubArray(vector<int>& nums) {
        int max =  nums[0], sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>max) max=sum;
            if(sum<0) sum=0;
        }
        return max;
}
```

```text
Time Complexity: O(n)
Space Complexity: O(1)
```

