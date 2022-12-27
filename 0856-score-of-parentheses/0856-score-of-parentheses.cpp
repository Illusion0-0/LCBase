class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char>st;
        int pos=s.size()-2, score=0;
        bool lelosum=false;
        for(int i=0;i<pos+2;i++){
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