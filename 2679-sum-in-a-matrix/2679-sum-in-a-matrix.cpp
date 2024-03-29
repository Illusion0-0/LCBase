class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        for(int i=0;i<n;i++){
            sort(nums[i].begin(),nums[i].end());
        }
        int score=0;
        for(int i=0;i<m;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                temp=max(temp,nums[j][i]);
            }
            score+=temp;
        }
        return score;
    }
};