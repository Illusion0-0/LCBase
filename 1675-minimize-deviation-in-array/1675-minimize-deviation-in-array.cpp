class Solution {
public:
    bool e(int a){return a%2==0;}
    bool o(int a){return a%2!=0;}
    
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minDiff = nums[n-1]-nums[0];
        set<int>s;
        for(int i:nums){
            if(e(i))s.insert(i);
            else s.insert(i*2);
        }
        while(e(*(--s.end()))){
            int first = *(s.begin());
            int last = *(--s.end());
            minDiff = min(minDiff, last-first);
            s.erase(last);
            s.insert(last/2);
            first = *(s.begin()), last = *(--s.end());
            minDiff = min(minDiff, last-first);
        }
        return minDiff;
    }
};