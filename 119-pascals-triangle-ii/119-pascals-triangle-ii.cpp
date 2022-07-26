class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<vector<int>>vec;
        int i=2,val=rowIndex;
        vector<int>temp;
        temp.push_back(1),vec.push_back(temp),temp.push_back(1);
        vec.push_back(temp),temp.clear();
        if(rowIndex==0)return {1};
        else if(rowIndex==1)return {1,1};
        else{
        rowIndex--;
        while(rowIndex--){
            temp.push_back(1);
            for(int j=0;j<vec[i-1].size()-1;j++){
                temp.push_back(vec[i-1][j]+vec[i-1][j+1]);
            }
            temp.push_back(1);
            vec.push_back(temp);
            temp.clear();
            i++;
        }
        return vec[val];  
        }
    }
};