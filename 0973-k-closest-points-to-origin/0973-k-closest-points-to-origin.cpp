class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>>ans;
        for(auto v:points){
            int distance = v[0]*v[0]+v[1]*v[1];
            ans.push_back({distance,{v[0],v[1]}});
        }
        sort(ans.begin(),ans.end());
        points.clear();
        for(int i=0;i<k;i++){
            points.push_back(ans[i].second);
        }
        return points;
    }
};