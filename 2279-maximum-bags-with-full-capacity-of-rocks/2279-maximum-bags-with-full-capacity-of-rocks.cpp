class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) {
        int n = rocks.size(), ans = 0;
        for(int i=0;i<n;i++){
            if(capacity[i]==rocks[i]) ans++;
            rocks[i] = capacity[i]-rocks[i];
        }
        sort(rocks.begin(),rocks.end());
        for(int i=0;i<n && extra>=rocks[i];i++){
            if(rocks[i])extra-=rocks[i], ans++;
        }
        return ans;
    }
};