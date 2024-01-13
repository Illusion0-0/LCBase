class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>m;
        for(char c:s){
            m[c]++;
        }
        for(char c:t){
            m[c]--;
        }
        int ans=0;
        for(auto i:m){
            if(i.second>0)ans+=i.second;
        }
        return ans;
        
    }
};