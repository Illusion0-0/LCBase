class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        unordered_map<int,int>cnt;
        for(int i=0;i<a.size();i++){
            int left = target - a[i];
            if(cnt.find(left)!=cnt.end())return {i,cnt[left]};
            cnt[a[i]] = i;
        }
        return {0,0};
    }
};