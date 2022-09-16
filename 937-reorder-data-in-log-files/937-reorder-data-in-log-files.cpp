class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<pair<string,string>>words;
        vector<string>ans,numbers;
        string s="",temp="";
        for(int i=0;i<n;i++){
            s="",temp="";
            int j=0;
            for(j=0;j<logs[i].size();j++){
                if(logs[i][j]==' ')break;
                s+=logs[i][j];
            }
            ++j;
            for(;j<logs[i].size();j++){
                temp+=logs[i][j];
            }
            if(!isdigit(temp[0]))
            words.push_back({temp,s});
            else{
                numbers.push_back(logs[i]);
            }
        }
        sort(words.begin(),words.end());
        for(auto i:words){
            // cout<<i.first[0]<<" "<<i.second<<endl;
            string s="";
            if(!isdigit(i.first[0])){
                s+=i.second+" "+i.first;
                ans.push_back(s);
            }
        }
        for(auto i:numbers){
            ans.push_back(i);
        }
        return ans;
    }
};