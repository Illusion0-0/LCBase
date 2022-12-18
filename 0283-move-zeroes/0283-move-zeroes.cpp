class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0,ind=0;i<nums.size();i++){
            if(nums[i]) 
                swap(nums[ind++],nums[i]);
        }
    }
};