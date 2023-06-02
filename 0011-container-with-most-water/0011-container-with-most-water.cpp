class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), ans = 0;
        int l = 0, r = n-1;
        while(l<r){
            int area = (r-l)*min(height[l],height[r]);
            // cout<<l<<":"<<r<<" = "<<area<<" "<<height[l]<<" - "<<height[r]<<endl;
            ans = max(ans,area);
            if(height[l]<=height[r])l++;
            else r--;
        }      
        // cout<<endl;
        return ans;
    }
};