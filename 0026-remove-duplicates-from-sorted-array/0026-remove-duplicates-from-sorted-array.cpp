class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,ans=0;
        for(i=0;i<nums.size();i++){
            // cout<<j<<" "<<i<<endl;
            if(nums[j]!=nums[i]){
                j++;
                ans++;
                nums[j]=nums[i];
            }
        }
        // for(int i:nums)cout<<i<<" ";
        return ans+1;
    }
};