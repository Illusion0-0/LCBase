class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> a(26,0), b(26,0), ans;
        for(char c:s1)a[c-'a']++;
        int n = s1.size();
        for(int i=0, j=0;i<s2.size();i++){
            b[s2[i]-'a']++;
            if((i+1)>=n){
                if(a==b)ans.push_back(j);
                b[s2[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};