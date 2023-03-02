class Solution {
public:
    int compress(vector<char>& s) {
        int c=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                c++;
                i--;
                s.erase(s.begin()+i+1);
            }else{
                if(c>1){
                    string p = to_string(c);
                    for(int j=0;j<p.size();j++,i++){
                        s.insert(s.begin()+i+1,p[j]);
                    }
                }
                c=1;
            }
        }
        if(c>1){
            string p = to_string(c);
            for(int j=0;j<p.size();j++){
                s.insert(s.end(),p[j]);
            }
        }
        return s.size();
    }
};