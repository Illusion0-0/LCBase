class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=1, temp=INT_MAX;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            (i+1<nums.size() && nums[i]==nums[i+1])?sum++:sum=1;
            if(nums[i]!=temp && sum>nums.size()/3){ans.push_back(nums[i]);
            temp = nums[i];}
        }
        return ans;
    }
};