class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(auto i:operations){
            m[i[1]]=m[i[0]];
            nums[m[i[0]]]=i[1];
        }
        return nums;
    }
};