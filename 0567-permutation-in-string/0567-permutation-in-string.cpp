class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26,0), b(26,0);
        for(char c:s1)a[c-'a']++;
        int n = s1.size();
        for(int i=0, j=0;i<s2.size();i++){
            b[s2[i]-'a']++;
            if((i+1)>=n){
                if(a==b)return true;
                b[s2[j]-'a']--;
                j++;
            }
        }
        return false;
    }
};