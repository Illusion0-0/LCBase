class Solution {
public:
    vector<vector<string>>ans;
    bool check(int row, int col, vector<string>&b){
        for(int i=0;i<row;i++){
            int r = i;
            int c = 0;
            for(int j=0;j<b.size();j++)
                if(b[i][j]=='Q')c=j;
            if(c==col || abs(row-r)==abs(col-c))return false;
        }
        return true;
    }
    
    void helper(vector<string>&b,int row){
        if(row==b.size()){
            ans.push_back(b);
            return;
        }
        for(int col=0;col<b.size();col++){
            if(check(row,col,b)){
                b[row][col]='Q';
                helper(b,row+1);
                b[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>b(n,string(n,'.'));
        helper(b,0);
        return ans;
    }
};