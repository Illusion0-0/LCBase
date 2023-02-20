class NumArray 
{
    vector<int> a, b;
    public:
    NumArray(vector<int>& nums) 
    {
        int n = size(nums);
        b = a = vector<int>(n, 0);
        b = nums;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j = (j | (j + 1)))
                a[j] += nums[i];
        }
        
    }
    
    void update(int index, int val) 
    {
        for(int i = index; i < a.size(); i = (i | (i + 1))){
            a[i] -= b[index];
            a[i] += val;
        }
        b[index] = val;
    }
    
    int sumRange(int left, int right) 
    {
        int total = 0;
        for(int i = right; i >= 0; i = (i & (i + 1)) - 1)
            total += a[i];
        
        for(int i = left - 1; i >= 0; i = (i & (i + 1)) - 1)
            total -= a[i];
        
        return total;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */