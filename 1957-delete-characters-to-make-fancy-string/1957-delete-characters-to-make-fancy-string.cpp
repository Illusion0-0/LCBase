class Solution {
public:
    string makeFancyString(string s) {
        int cnt=0, flag = 0, n = s.size();
        string ans="";
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1])flag=0,cnt=0;
            else cnt++;
            if(cnt>=2)continue;
            ans+=s[i];
        }
        if(!flag)ans+=s[n-1];
        return ans;
    }
};