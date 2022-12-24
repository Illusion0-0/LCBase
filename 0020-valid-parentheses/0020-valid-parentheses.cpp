class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else if(st.size()){
                char c;
                if(st.size())c=st.top();
                if((c=='(' && s[i]==')')||(c=='[' && s[i]==']')||(c=='{' && s[i]=='}'))st.pop();
                else return false;
            }
            else return false;
        }
        return st.empty();
    }
};