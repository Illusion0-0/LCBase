class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        int n=nums.size();
        while(n--){
            vector<int>ok;
            for(auto &i:m){
                if(i.second>0){
                ok.push_back(i.first);
                i.second--;
                }
            }
            if(!ok.size())break;
            ans.push_back(ok);
        }
        return ans;
    }
};