class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>b = n;
        uint32_t ans=0;
        for(int i=31;i>=0;i--){
            ans+=b[i]*pow(2,31-i);
        }
        return ans;
    }
};