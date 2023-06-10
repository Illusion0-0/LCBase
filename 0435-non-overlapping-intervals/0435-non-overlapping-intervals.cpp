class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            if(v[i][1]<=v[i+1][0])continue;
            v[i+1][0] = v[i][0];
            v[i+1][1] = min(v[i][1],v[i+1][1]);
            ans++;
        }
        return ans;
    }
};