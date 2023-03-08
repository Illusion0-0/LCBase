class Solution {
public:
    int queen[10];
    
    bool check(int row, int col){
        for(int i=0;i<row;i++){
            int r = i;
            int c = queen[i];
            if(c==col || abs(row-r)==abs(col-c))return false;
        }
        return true;
    }
    
    int helper(int row, int n){
        if(row==n) return 1;
        int ans=0;
        for(int col=0;col<n;col++){
            if(check(row,col)){
                queen[row]=col;
                ans+=helper(row+1,n);
            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        return helper(0,n);
    }
};