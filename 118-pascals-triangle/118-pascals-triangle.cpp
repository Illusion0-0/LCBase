class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec;
        int i=2,val=1;
        vector<int>temp;
        temp.push_back(1),vec.push_back(temp),temp.push_back(1);
        vec.push_back(temp),temp.clear();
        if(numRows==1)return {{1}};
        else{
        numRows-=2;
        while(numRows--){
            temp.push_back(1);
            for(int j=0;j<vec[i-1].size()-1;j++){
                temp.push_back(vec[i-1][j]+vec[i-1][j+1]);
            }
            temp.push_back(1);
            vec.push_back(temp);
            temp.clear();
            i++;
        }
        return vec;
        }
    }
};