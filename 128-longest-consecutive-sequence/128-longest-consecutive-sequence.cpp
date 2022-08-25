class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans=1, maxy = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])continue;
            if(nums[i+1]-nums[i]==1)ans++;
            else{
            maxy = max(maxy,ans);
            ans=1;
            }
        }
        maxy = max(ans,maxy);
        return n?maxy:0;
    }
};