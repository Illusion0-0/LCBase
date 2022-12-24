class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        vector<pair<int,int>>v;
        vector<int>ans;
        for(auto i:m){
            v.push_back({i.second,i.first});
        }
        priority_queue<pair<int,int>>pq(v.begin(),v.end());
        v.clear();
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};