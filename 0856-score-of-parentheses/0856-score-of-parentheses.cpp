class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char>st;
        int score=0;
        bool lelosum=false;
        for(int i=0;i<s.size();i++){
            int sz = st.size()-1;
            if(s[i]==')'){
                if(lelosum) 
                    score+=pow(2,sz),lelosum=false;
                st.pop();
            }
            else{
                st.push(s[i]);
                lelosum=true;
            }
        }
        return score;
    }
};