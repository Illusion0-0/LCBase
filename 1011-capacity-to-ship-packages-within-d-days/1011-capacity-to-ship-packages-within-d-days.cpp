class Solution {
public:
    int shipWithinDays(vector<int>& nums, int k) {
        int l=0, r=0, n=nums.size();
        for(int i:nums)r+=i;
        while(l<=r){
            int mid = l+(r-l)/2;
            int day=0, sum=0;
            for(int i=0;i<n;i++){
                if(nums[i]>mid)day=k+1;
                if(sum+nums[i]<=mid) sum+=nums[i];
                else{
                    sum=nums[i];
                    day++;
                }
            }
            if(day<k) r=mid-1;
            else l=mid+1;                
        }
        return l;
    }
};