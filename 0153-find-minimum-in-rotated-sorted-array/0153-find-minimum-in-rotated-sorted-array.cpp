class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[l]<=nums[mid]){
                if(nums[l]>nums[r]) l=mid+1;
                else r=mid-1;
            }else{
                r=mid;
            }
        }
        return nums[l];
    }
};