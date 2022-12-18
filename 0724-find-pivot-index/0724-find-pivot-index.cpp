class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,total=0;
        for(int i=0;i<nums.size();i++) total+=nums[i];
        for(int i=0;i<nums.size()-1;i++){
            if(total-sum-nums[i] == sum)return i;
            sum+=nums[i];
            if(total-sum-nums[i+1] == sum)return i+1;
        }
        return (nums.size()>1?-1:0);
    }
};