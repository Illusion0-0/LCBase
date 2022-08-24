class Solution {
public:
    // map, sort and update maxsum or print nums[n/2]
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};