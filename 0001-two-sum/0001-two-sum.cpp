class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        unordered_map<int, int> imap;
        for (int i = 0;; ++i) {
            auto it = imap.find(target - a[i]);
            if (it != imap.end()) 
                return {i, it->second};
            imap[a[i]] = i;
        }
    }
};