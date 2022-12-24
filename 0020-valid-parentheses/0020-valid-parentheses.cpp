class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int>start={{'(',1},{'[',2},{'{',3}},end={{')',-1},{']',-2},{'}',-3}};
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(start[s[i]]){
                st.push(s[i]);
            }else if(st.size()){
                if(start[st.top()]+end[s[i]]==0)st.pop();
                else return false;
            }
            else return false;
        }
        if(st.size())return false;
        return true;
    }
};