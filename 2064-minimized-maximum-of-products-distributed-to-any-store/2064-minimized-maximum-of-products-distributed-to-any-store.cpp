class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l=1, r=*max_element(q.begin(),q.end());
        while(l<=r){
            int mid = (l+r)/2;
            int c=0;
            for(int i:q){
                // if mid is the ans then to check in how many stores product[i] can goto
                c+=i/mid;
                // if something is left (which will definitely be less than mid) 
                // in product[i] even after above it can goto another store
                if(i%mid)c++;
            }
            if(c>n) // mid is not enough because it is distributing product[i] to multiple stores which is not allowed
                l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};