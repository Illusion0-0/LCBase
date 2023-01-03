class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size(), ans = 0;
        vector<int>diff;
        for(int i=0;i<n;i++){
            diff.push_back(capacity[i]-rocks[i]);
            if(capacity[i]==rocks[i]) ans++;
        }
        priority_queue<int, vector<int>, greater<int>>pq(diff.begin(),diff.end());
        while(!pq.empty()){
            if(additionalRocks && pq.top() && pq.top()<=additionalRocks){
                ans++;
                additionalRocks-=pq.top();
            }
            pq.pop();
        }
        return ans;
    }
};