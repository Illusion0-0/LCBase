class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2)return {};
        vector<long long>ans;
        for(int i=2;i<=finalSum;i+=2){
            if(finalSum-i<i+2){
                ans.push_back(finalSum);
                break;
            }
            ans.push_back(i);
            finalSum-=i;
        }
        return ans;
    }
};