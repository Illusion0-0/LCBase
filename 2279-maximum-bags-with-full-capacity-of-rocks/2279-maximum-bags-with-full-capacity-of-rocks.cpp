class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size(), ans = 0;
        vector<int>diff;
        for(int i=0;i<n;i++){
            diff.push_back(capacity[i]-rocks[i]);
            if(capacity[i]==rocks[i]) ans++;
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<n;i++){
            if(additionalRocks && diff[i] && diff[i]<=additionalRocks){
                ans++;
                additionalRocks-=diff[i];
            }
        }
        return ans;
    }
};