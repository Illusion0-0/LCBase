class Solution {
public:
    int chk(int mid, vector<int>& nums){
        int sum=0;
        for(int i:nums)
            sum+=ceil((double)i/mid);
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxn = *max_element(nums.begin(),nums.end());
        cout<<maxn<<endl;
        int low=1, high=maxn, ans=INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(chk(mid, nums)<=threshold){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};