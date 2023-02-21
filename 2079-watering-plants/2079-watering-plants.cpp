class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int sum=0, n = plants.size();        
        vector<int>pre(n);
        for(int i=0;i<n;i++){
            sum+=plants[i];
            pre[i]=sum;
        }
        int ans=0, extra=0;
        while(true){
            int c = capacity+extra;
            int x = upper_bound(begin(pre),end(pre),c)-begin(pre);
            // cout<<x<<" - "<<c<<" ";
            if(x<n){
                ans+=2*x;
                extra = pre[x-1];
            }
            else{
                ans+=x;
                // cout<<ans<<". ";
                break;
            }
            // cout<<ans<<" ";
        }
        cout<<endl;
        return ans;
    }
};