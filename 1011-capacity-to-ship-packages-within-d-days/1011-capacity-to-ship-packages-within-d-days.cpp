class Solution {
public:
    int shipWithinDays(vector<int>& nums, int k) {
        int l=0,r=0;
        for(int i:nums)l=max(l,i),r+=i;
        while(l<=r){
            int mid = l+(r-l)/2;
            int sum=0, div=1;
            for(int i:nums){
                if(sum+i<=mid) sum+=i;
                else{
                    div++;
                    sum=i;
                }
            }
            if(div<=k)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};