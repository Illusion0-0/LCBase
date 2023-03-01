vector<int>v(100001,0);
class Solution {
public:
    unordered_map<int,int>m;
    vector<int> sortArray(vector<int>& nums) {
        vector<int>ans;
        for(int i:nums){
            int x = i+(5*10000);
            v[x]=1;
            m[x]++;
        }
        for(int i=0;i<100001;i++){
            if(v[i]==1)
            for(int j=0;j<m[i];j++){
                ans.push_back(i-(5*10000));
            }
        }
        return ans;
    }
};