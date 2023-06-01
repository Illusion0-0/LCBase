class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>fwd(n,1), bwd(n,1), ans(n);
        int fprod=1, bprod=1;
        for(int i=0;i<n;i++){
            fprod*=nums[i];
            bprod*=nums[n-i-1];
            fwd[i] = fprod, bwd[n-i-1]=bprod;
        }
        for(int i=0;i<n;i++){
            if(i-1>=0 && i+1<n){
                ans[i] = fwd[i-1]*bwd[i+1];
            }
            else if(i-1<0){
                ans[i] = 1*bwd[i+1];
            }
            else{
                ans[i] = fwd[i-1]*1;
            }
        }
        return ans;
    }
};