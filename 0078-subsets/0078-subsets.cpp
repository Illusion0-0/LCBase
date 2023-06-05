class Solution {
public:
    vector<vector<int>>ans;
    
    void rec(vector<int>& nums, vector<int>& ok, int i){
        if(i>=nums.size()){
            ans.push_back(ok);
            return;
        }
        ok.push_back(nums[i]);
        rec(nums,ok,i+1);
        ok.pop_back();
        rec(nums,ok,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>ok;
        rec(nums,ok,0);
        return ans;
    }
};