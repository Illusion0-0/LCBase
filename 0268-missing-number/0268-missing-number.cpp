class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xo=0;
        for(int i=0;i<=nums.size();i++){
            xo^=i;
        }
        for(int i=0;i<nums.size();i++){
            xo^=nums[i];
        }
        return xo;
    }
};