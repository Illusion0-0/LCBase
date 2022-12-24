class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=2*nums.size();
        for(int i=0;i<n/2;i++){
            nums.push_back(nums[i]);
        }
        stack<int>s;
        vector<int>ans(n/2,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i]){
                if(s.top()>=n/2)s.top()-=n/2;
                ans[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};