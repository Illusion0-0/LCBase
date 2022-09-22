class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        map<int,int>ans;
        for(int i:nums2){
            while(!s.empty() && i>s.top())
            {
                ans[s.top()]=i;
                if(!s.empty())s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            ans[s.top()]=-1;
            s.pop();
        }
        vector<int>v;
        for(int i:nums1){
            v.push_back(ans[i]);
        }
        return v;
        
    }
};