class Solution {
public:
    
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        int n = profits.size();
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        priority_queue<int>pq;
        sort(v.begin(),v.end());
        int j=0;
        while(k--){
            while(j<n && v[j].first<=w){
                pq.push(v[j].second);
                j++;
            }
            if(pq.empty())break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};