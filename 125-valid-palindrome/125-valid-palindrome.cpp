class Solution {
public:
    
    bool checkPal(string &s, int l, int r){
	    if(l>=r)return true;
        if(s[l]!=s[r]){
            return false;
        }
        return checkPal(s,l+1,r-1);
    }
    
    bool isPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i]))
            ans += (char)tolower(s[i]);
            else continue;
        }
        cout<<ans<<endl;
        return checkPal(ans,0,ans.size()-1);
    }
};