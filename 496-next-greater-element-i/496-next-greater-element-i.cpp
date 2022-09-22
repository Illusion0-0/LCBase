class Solution {
public:
    int ans[10001]{0};
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
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
        nums2.clear();
        for(int i:nums1){
            nums2.push_back(ans[i]);
        }
        return nums2;
        
    }
};