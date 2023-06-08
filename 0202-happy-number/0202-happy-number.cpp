class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        unordered_map<string,int>m;
        while(true){
            int k = 0;
            m[s]++;
            for(int i=0;i<s.size();i++) 
                k+=(s[i]-'0')*(s[i]-'0');
            s = to_string(k);
            if(k==1)return true;
            if(m[s])return false;
        }
        // cout<<endl;
        return false;
    }
};