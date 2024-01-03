class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        int cnt=0;
        for(auto s:bank){
            cnt=0;
            for(char c:s){
                if(c=='1')cnt++;
            }
            if(cnt)v.push_back(cnt);
        }
        int ans=0;
        if(v.size())
        for(int i=0;i<v.size()-1;i++){
            ans+=(v[i]*v[i+1]);
        }
        return ans;
    }
};