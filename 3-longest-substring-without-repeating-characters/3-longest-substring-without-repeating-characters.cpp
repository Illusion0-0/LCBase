class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length(), l=0, ans=0;
      map<char,int>m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
        while(m[s[i]]>1){
            m[s[l]]--;
            l++;
        }
        ans = max(ans,(i-l)+1);
    }
      return ans;
  }
};