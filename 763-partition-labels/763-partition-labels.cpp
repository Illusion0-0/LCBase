class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>m,chk;
        int n = (int)s.length();
        vector<int>ans;
        stack<char>st,temp;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        char max_cnt;
        int i=0,pos=0,cnt=INT_MIN,flag=-1;
        for(i=0;i<n;i++){
            if(chk[s[i]]==0){
                temp=st;
                while(!temp.empty()){
                    char ch = temp.top();
                    if(chk[ch]==m[ch])temp.pop();
                    else {flag=1;break;}
                }
                if(flag || flag==-1){
                    flag=0;
                    chk[s[i]]++;
                    st.push(s[i]);
                }
                else {
                    ans.push_back(i-pos);
                    st.empty();
                    st.push(s[i]);
                    chk[s[i]]++;
                    pos=i;
                }
            }
            else{
                chk[s[i]]++;
            }
        }
        ans.push_back(i-pos);
        return ans;
    }
};