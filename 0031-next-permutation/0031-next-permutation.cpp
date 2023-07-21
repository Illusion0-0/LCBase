class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int pos=-1;
        for (int i = nums.size() - 1; i > 0; i--) 
        {
            if(nums[i-1]<nums[i]){
                pos=i-1;
                break;
            }
        }
        if(pos!=-1){
        int x = nums[pos],pos2=-1;
        for (int i = pos+1; i < nums.size(); i++)
        {
            if(nums[i]>x){
                pos2=i;
            }
        }
        
        if(pos2!=-1){
            swap(nums[pos],nums[pos2]);
        }
        reverse(nums.begin() + pos + 1, nums.end());
        }
        else reverse(nums.begin(),nums.end());
        for (auto i : nums)
            cout << i << " ";
    }
};