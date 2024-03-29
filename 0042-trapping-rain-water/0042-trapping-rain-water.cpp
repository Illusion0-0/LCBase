class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, n = height.size();
        vector<int>maxb(n+1,0);
        int maxn=0;
        for(int i=n-1;i>=0;i--){
            maxn=max(maxn,height[i]);
            maxb[i]=maxn;
        }
        int l=0,r=0;
        for(int i=0;i<n;i++){
            r = maxb[i+1];
            if(min(l,r)>height[i]){
                ans+=abs(height[i]-min(l,r));                
            }            
            l=max(l,height[i]);
        }
        return ans;
    }
};