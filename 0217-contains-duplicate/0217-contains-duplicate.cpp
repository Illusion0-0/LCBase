class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int i:nums){
            m[i]++;
            if(m[i]>1)return true;
        }
        return false;
    }
};