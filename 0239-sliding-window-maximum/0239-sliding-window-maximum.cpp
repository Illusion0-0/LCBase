class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        deque<int>d;
        for(int i=0;i<n;i++){
            if(!d.empty() && d.front()<(i+1)-k)d.pop_front();
            while(!d.empty() && nums[d.back()]<nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[d.front()]);
            }
        }
        return ans;
    }
};