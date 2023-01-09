class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]+=1;
        reverse(digits.begin(),digits.end());
        int carry=0;
        for(int &i:digits){
            if(carry)i+=carry;
            carry = i/10;
            i = i%10;
        }
        if(carry)digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};