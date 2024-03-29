class NumArray {
public:
    vector<int>pref;
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
            pref.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return (left-1<0)?pref[right]:pref[right]-pref[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */