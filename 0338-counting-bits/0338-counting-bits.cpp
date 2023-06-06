class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            bitset<32>b = i;
            int one=0;
            for(int i=0;i<32;i++) if(b[i]) one++;
            ans.push_back(one);
        }
        return ans;
    }
};