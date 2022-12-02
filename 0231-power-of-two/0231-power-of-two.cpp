class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        long double k = log10(n)/log10(2);
        return (k==(int)k);
    }
};