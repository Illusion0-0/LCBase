class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        unordered_map<int,pair<int,int>>cnt;
        for(int i=0;i<a.size();i++){
            int left = target - a[i];
            if(cnt.find(left)!=cnt.end())return {i,cnt[left].second};
            cnt[a[i]] = {a[i],i};
        }
        return {0,0};
    }
};