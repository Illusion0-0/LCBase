class Solution {
public:
    bool isvowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    
    int maxVowels(string s, int k) {
        int n = s.size();
        int sum=0;
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++){
            if(isvowel(s[i])){
                sum++;
            }
            pre[i+1]=sum;
        }
        int ans=0;
        for(int i=0;i<=n-k;i++){
            ans=max(ans,pre[i+k]-pre[i]);
        }
        return ans;
    }
};