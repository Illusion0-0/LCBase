class Solution {
public:
    // map, sort and update maxsum or print nums[n/2]
    int majorityElement(vector<int>& nums) {
        // O(N) approach with O(1) space is Moore Voting Algo
        int me=0;
        for(int i=0,count=0;i<nums.size();i++){
            if(nums[i]==nums[me])count++;
            else count--;
            if(count==0){
                me=i;
                count=1;
            }
        }
        return nums[me];
    }
};