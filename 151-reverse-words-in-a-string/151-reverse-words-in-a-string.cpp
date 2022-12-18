class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string str="";
        int n = s.size(),space=0,flag=0;
        for(int i=0;i<n;i++){
            if(flag==1 && i-1>=0 && s[i]!=' ' && s[i-1]==' '){
                v.push_back(str);
                str="";
                str+=' ';
                v.push_back(str);
                str="";
            }
            if(s[i]!=' '){
                flag=1;
                str+=s[i];
            }
            
        }
        if(str.size())v.push_back(str);
        // if(space.size())v.push_back(space);
        reverse(v.begin(),v.end());
        s.clear();
        for(auto i:v){
            s+=i;
        }
        return s;
    }
};