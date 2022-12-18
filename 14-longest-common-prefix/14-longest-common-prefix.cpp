class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans="";
        for (int i = 0; i < strs[0].size(); i++)
        {
            int flag=0;
            for (int j = 0; j < n-1; j++)
            {
                if(strs[j][i]!=strs[j+1][i]){
                    flag=1;
                    break;
                }
            }
            if(flag)return ans;
            else ans+=strs[0][i];
        }
        return ans;
    }
};