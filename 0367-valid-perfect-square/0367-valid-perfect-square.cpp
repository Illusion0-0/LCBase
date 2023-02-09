class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=0, r=(long long)pow(2,31)-1;
        while(l<=r){
            double mid = l+(r-l)/2;
            if(mid == num/mid){cout<<mid;return true;}
            else if(mid<num/mid)l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};