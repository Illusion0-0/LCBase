class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<string>copy = s;
        for(string &s:copy){
            sort(s.begin(),s.end());
        }
        unordered_map<string,vector<int>>cnt;
        for(int i=0;i<copy.size();i++){
            cnt[copy[i]].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it: cnt){
            vector<string>tmp;
            for(int i:it.second){
                tmp.push_back(s[i]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};