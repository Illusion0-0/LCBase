class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        if(r<0)return {-1,-1};
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        vector<int>ans;
        if(l>nums.size()-1 || nums[l]!=target)l=-1;
        ans.push_back(l);
        l=0,r=nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(r<0 || nums[r]!=target)r=-1;
        ans.push_back(r);
        return ans;
    }
};