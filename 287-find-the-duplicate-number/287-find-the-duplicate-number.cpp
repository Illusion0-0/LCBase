class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int k = 0, ans=0;
        while(1){
            nums[k]*=-1;
            ans=k;
            k = -1*nums[k];
            if(k<0)break;
        }
        for(int i:nums)if(i<0)i*=-1;
        return ans;
    }
};