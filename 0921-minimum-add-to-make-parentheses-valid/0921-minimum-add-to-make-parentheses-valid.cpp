class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size(), cnt=0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(s[i]);
            if(s[i]==')' && st.size()==0)cnt++;
            else if(s[i]==')' && !st.empty())st.pop();
        }
        return cnt+st.size();
    }
};