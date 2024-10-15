class Solution {
public:
    long long minimumSteps(string s) {
        int o=0;
        for(char c:s){
            if(c=='0')o++;
        }    
        long sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                sum+=(o-i);
                o++;
            }
        }
        return sum;
        
    }
};