class Solution {
public:
    vector<vector<int>>ans;
    // vector<int>temp;

    void helper(int j, int sum, vector<int>& v, int target, vector<int> temp){
        if(j==v.size())return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        else if(sum>target)return;
        for(int i=j;i<v.size();i++){
            sum+=v[i];
            temp.push_back(v[i]);
            helper(i,sum,v,target,temp);
            sum-=v[i];
            temp.pop_back();
        }        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<int>temp;
        helper(0,0,v,target,temp);
        return ans;
    }
};