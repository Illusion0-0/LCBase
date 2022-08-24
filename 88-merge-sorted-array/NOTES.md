[Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

1. num1+num2 followed by sort

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
}
```

```text
Time Complexity: O(N*logN) {N = m+n}
Space Complexity: O(1)
```