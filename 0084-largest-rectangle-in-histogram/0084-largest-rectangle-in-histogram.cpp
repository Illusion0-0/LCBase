class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,0),right(n,0);
        stack<int>s;
        for(int i=0;i<n;i++){
            int lmin=-1;
            while(!s.empty() && heights[i]<=heights[s.top()]){
                lmin=s.top();
                s.pop();
            }
            if(!s.empty())lmin=s.top();
            else lmin=-1;
            s.push(i);
            left[i]=lmin;
        }
        for(int i=0;i<n;i++)cout<<left[i]<<" ";
        cout<<endl;
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            int rmin=n-1;
            while(!s.empty() && heights[i]<=heights[s.top()]){
                rmin=s.top()-1;
                s.pop();
            }
            if(!s.empty())rmin=s.top()-1;
            else rmin=n-1;
            s.push(i);
            right[i]=rmin;
        }
        int maxn=0;
        for(int i=0;i<n;i++){
            maxn = max(maxn,(right[i]-left[i])*heights[i]);
        }
        return maxn;
    }
};