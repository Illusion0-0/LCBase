class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size()==1)return 0;
        vector<int>v;
        int cnt=0;
        for(auto s:bank){
            cnt=0;
            for(char c:s){
                if(c=='1')cnt++;
            }
            cout<<cnt<<" ";
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