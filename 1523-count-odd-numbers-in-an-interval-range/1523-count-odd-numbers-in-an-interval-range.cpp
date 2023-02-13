class Solution {
public:
    int countOdds(int low, int high) {
        int a = low/2, b = high/2;
        return high%2?b-a+1:b-a;
    }
};