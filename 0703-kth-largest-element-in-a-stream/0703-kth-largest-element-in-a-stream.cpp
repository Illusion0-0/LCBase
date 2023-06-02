class KthLargest {
public:
    multiset<int,greater<int>>m;
    int ind=0;
    KthLargest(int k, vector<int>& nums) {
        ind=k;
        for(int i:nums){m.insert(i); if(m.size()>k)m.erase(--m.end());}
    }
    
    int add(int val) {
        m.insert(val);
        if(m.size()>ind)m.erase(--m.end());
        return *(--m.end());
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */