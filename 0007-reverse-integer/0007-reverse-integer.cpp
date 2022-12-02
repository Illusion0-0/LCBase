class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        int i = 0;
        for (i = 0; i < s.size(); i++) {
          if (i == '-' || i == '0')
            continue;
          else
            break;
        }
        s = s.substr(i, s.size() - i);
        long long ans = stoll(s);
        if (x < 0) ans *= -1;
        if(ans>2147483647 || ans<-2147483648)return 0;
        return ans;
    }
};