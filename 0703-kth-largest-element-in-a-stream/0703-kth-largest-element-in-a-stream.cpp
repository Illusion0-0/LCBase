class KthLargest {
public:
    multiset<int,greater<int>>m;
    int ind=0;
    KthLargest(int k, vector<int>& nums) {
        ind=k;
        for(int i:nums)m.insert(i);
    }
    
    int add(int val) {
        m.insert(val);
        auto it=m.begin();
        for(int i=1;i<ind;i++) it++;
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */