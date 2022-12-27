class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int lmin=-1,n = heights.size(), maxn=0;
        int h = 0, rmin = n-1;
        stack<int>s;
        for(int i=0;i<n;i++){
            lmin=-1;
            while(!s.empty() && heights[i]<=heights[s.top()]){
                rmin=i,lmin=-1;
                h = heights[s.top()];
                s.pop();
                if(!s.empty())lmin=s.top();
                maxn = max(maxn,(rmin-lmin-1)*h);
            }
            s.push(i);
        }
        return maxn;
    }
};