class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            map<char,int>m,p;
            for(int j=0;j<9;j++){
                m[board[i][j]]++;
                p[board[j][i]]++;
                if(m[board[i][j]]>1 && board[i][j]!='.')return false;
                if(p[board[j][i]]>1 && board[j][i]!='.')return false;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                map<char,int>m;
                for(int row=i;row<i+3;row++){
                    for(int col=j;col<j+3;col++){
                        m[board[row][col]]++;
                        if(m[board[row][col]]>1 && board[row][col]!='.')return false;
                    }
                }
            }
        }
        return true;
    }
};