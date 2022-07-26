class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int>ans;
       ans.push_back(1);
       long long val=1;
       for(int i=0;i<rowIndex;i++){
           val=val*(rowIndex-i)/(i+1);
           ans.push_back(val);
       } 
       return ans;
    }
};