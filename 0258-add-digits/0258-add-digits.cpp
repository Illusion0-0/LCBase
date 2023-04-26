class Solution {
public:
    int addDigits(int num) {
        while(to_string(num).length()>1){
            int sum=0;
            string s = to_string(num);
            for(int i=0;i<s.length();i++){
                sum+=(s[i]-'0');        
            }
            num=sum;
        }
        return num;
    }
};