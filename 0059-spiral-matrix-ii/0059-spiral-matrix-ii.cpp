class Solution {
public:
    vector<vector<int>>ans;
    int i=0, j=0, val=1;
    
    void fillRight(int n){
        while(j<n && ans[i][j]!=0){
            j++;
        }
        while(j<n && ans[i][j]==0){
            ans[i][j] = val;
            val++;
            j++;
        }
        j--;
    }
    
    void fillDown(int n){
        while(i<n && ans[i][j]!=0){
            i++;
        }
        while(i<n && ans[i][j]==0){
            ans[i][j] = val;
            val++;
            i++;
        }
        i--;
    }
    
    void fillLeft(int n){
        while(j>=0 && ans[i][j]!=0){
            j--;
        }
        while(j>=0 && ans[i][j]==0){
            ans[i][j] = val;
            val++;
            j--;
        }
        j++;
    }
    
    void fillUp(int n){
        while(i>=0 && ans[i][j]!=0){
            i--;
        }
        while(i>=0 && ans[i][j]==0){
            ans[i][j] = val;
            val++;
            i--;
        }
        i++;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        ans.resize(n,vector<int>(n,0));
        char choice='r';
        while(true){
            switch(choice){
                case 'r':   fillRight(n); break;
                case 'd':   fillDown(n); break;
                case 'l':   fillLeft(n); break;
                case 'u':   fillUp(n); break;
            }
            if(j+1<n && ans[i][j+1]==0)choice = 'r';
            else if(i+1<n && ans[i+1][j]==0)choice = 'd';
            else if(j-1>=0 && ans[i][j-1]==0)choice = 'l';
            else if(i-1>=0 && ans[i-1][j]==0)choice = 'u';
            else break;
        }
        return ans;
    }
};