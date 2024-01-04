class Solution {
public:
    int minOperations(vector<int>& nums) {
        // n%3==1 > (n/3)+1
        // n%3==0 > n/3
        // n%3==2 > (n/3)+1
        unordered_map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        int ans=0;
        for(auto x:m){
            int n = x.second;
            if(n==1) return -1;
            else if(n%3==0) ans+=n/3;
            else ans+=(n/3)+1;
        }
        return ans;
    }
};