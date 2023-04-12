class Solution {
public:
    string simplifyPath(string path) {
        path+='/';
        int n = path.length();
        vector<string>ans;
        string temp="";
        for(int i=1;i<n;i++){
            if(path[i-1]=='/' && path[i]=='/')continue;
            if(path[i]!='/'){
                temp.push_back(path[i]);
            }
            else{
                cout<<temp<<" ";
                if(temp.size()==1 && temp[0]=='.'){temp="";continue;}
                else if(temp.size()==2 && temp[0]==temp[1] && temp[0]=='.'){
                    if(ans.size())ans.pop_back();
                    temp="";
                }
                else{
                    ans.push_back(temp);
                    temp="";
                }
            }
        }
        string res="/";
        for(string k:ans){
            res+=k;
            res.push_back('/');
        }
        if(res.size()>1)res.pop_back();
        cout<<endl;
        return res;
    }
};