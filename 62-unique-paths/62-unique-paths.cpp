class Solution {
public:
    int ncr(int n, int r){
        long long ans=1;
        for (int i = 1; i <= r; i++) {
            ans *= (n - r )+ i;
            ans /= i;
        }
        return ans;
    }
    
    int uniquePaths(int m, int n) {
        m--,n--;
        return ncr(m+n,m);
    }
};