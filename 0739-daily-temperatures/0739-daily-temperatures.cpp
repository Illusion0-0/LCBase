class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>ngi;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(ngi.size() && temperatures[i]>temperatures[ngi.top()]){
                int topVal = temperatures[ngi.top()];
                ans[ngi.top()] = i-ngi.top();
                ngi.pop();
            }
            ngi.push(i);
        }
        return ans;
    }
};