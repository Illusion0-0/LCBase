class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        intervals.push_back({0,0});
        for(int i=0;i<n;i++){
            if(intervals[i][1]<intervals[i+1][0]){
                ans.push_back({intervals[i][0],intervals[i][1]});
                continue;
            }
            int j=i, l=intervals[i][0], r=intervals[i][1];
            while(j+1<n and r>=intervals[j+1][0]){
                r=max(intervals[j+1][1],r);
                j++;
            }
            cout<<i<<" "<<j<<endl;
            i=j;
            ans.push_back({l,r});
        }
        cout<<endl;
        return ans;
    }
};