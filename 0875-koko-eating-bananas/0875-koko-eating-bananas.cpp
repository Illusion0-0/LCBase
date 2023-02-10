class Solution {
public:
    int minEatingSpeed(vector<int>& q, int n) {
        int l=1, r=*max_element(q.begin(),q.end());
        while(l<=r){
            int mid = (l+r)/2;
            long long c=0;
            for(int i:q){
                c+=i/mid;
                if(i%mid)c++;
            }
            if(c>n)
                l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};