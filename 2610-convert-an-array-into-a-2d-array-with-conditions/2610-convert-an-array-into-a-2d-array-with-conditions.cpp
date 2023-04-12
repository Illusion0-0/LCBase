class Solution {
public:
    int m[201];
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        for(int i:nums){
            m[i]++;
        }
        int n=nums.size();
        while(n--){
            vector<int>ok;
            for(int i=0;i<=200;i++){
                if(m[i]>0){
                ok.push_back(i);
                m[i]--;
                }
            }
            if(!ok.size())break;
            ans.push_back(ok);
        }
        return ans;
    }
};