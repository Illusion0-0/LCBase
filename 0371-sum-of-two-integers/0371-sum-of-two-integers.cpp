class Solution {
public:
    int getSum(int a, int b) {
        double x = log(pow(2,a)*pow(2,b));
        // = a*log(2)+b*log(2)
        return (int)ceil(x/log(2));
    }
};