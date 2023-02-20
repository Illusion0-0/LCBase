class RangeFreqQuery {
public:
    vector<vector<int>>m = vector<vector<int>>(10005);
    RangeFreqQuery(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++){
            m[a[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int ans=0;
        int first = lower_bound(begin(m[value]),end(m[value]),left)-begin(m[value]);
        int last = upper_bound(begin(m[value]),end(m[value]),right)-begin(m[value]);
        // if(last==temp.size())--last;
        ans = (last-first);
        // if(first)
        return ans;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */