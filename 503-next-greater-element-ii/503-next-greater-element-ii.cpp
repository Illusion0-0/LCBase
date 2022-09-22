class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        vector<int>v=nums;
        map<int,queue<int>>ans;
        int val=-1;
        for(int i:nums){
            v.push_back(i);
        }
        for(int i:nums){
            if(i>nums[nums.size()-1]){
                val=i;
                break;
            }
        }
        for(int i:v){
            while(!s.empty() && i>s.top()){
                ans[s.top()].push(i);
                s.pop();
            }
            s.push(i);
        }
        if(val!=-1)s.push(val);
        v.clear();
        for(int i:nums){
            v.push_back((ans[i].size())?ans[i].front():-1);
            if(!ans[i].empty())ans[i].pop();
        }
        return v;
    }
};