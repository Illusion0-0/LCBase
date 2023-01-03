class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size(), ans = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<n;i++){
            if(capacity[i]==rocks[i]) ans++;
            else pq.push(capacity[i]-rocks[i]);
        }
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