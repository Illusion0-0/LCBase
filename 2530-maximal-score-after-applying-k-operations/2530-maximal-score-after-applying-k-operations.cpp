class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(int i:nums){
            q.push(i);
        }
        long sum=0;
        while (k--) {
            int n = q.top();
            sum+=n;
            q.pop();
            q.push((n+3-1)/3); 
        }
        return sum;
    }
};