class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        set<int>st;
        while(true){
            int k = 0;
            st.insert(stoi(s));
            for(int i=0;i<s.size();i++) 
                k+=(s[i]-'0')*(s[i]-'0');
            s = to_string(k);
            if(k==1)return true;
            if(st.find(k)!=st.end())return false;
        }
        // cout<<endl;
        return false;
    }
};