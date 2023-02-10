class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        sort(nums.begin(),nums.end());
        r=nums[n-1]-nums[0];
        while(l<=r){
            int mid = (l+r)/2;
            int le=0,c=0;
            for(int ri=1;ri<n;ri++){
                while(nums[ri]-nums[le]>mid)le++;
                c+=(ri-le);
            }
            if(c>=k)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};