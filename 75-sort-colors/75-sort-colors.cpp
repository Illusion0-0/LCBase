class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)a++;
            else if(nums[i]==1)b++;
            else c++;
        }
        int k=0;
        for(int i=0;i<a;i++,k++){
            nums[k]=0;
        }
        for(int i=0;i<b;i++,k++){
            nums[k]=1;
        }
        for(int i=0;i<c;i++,k++){
            nums[k]=2;
        }
    }
};