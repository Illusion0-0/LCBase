class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        vector<int>knum,ans;
        while(k){
            int x = k%10;
            knum.push_back(x);
            k/=10;
        }
        reverse(a.begin(),a.end());
        int carry = 0;
        if(a.size()>knum.size())swap(a,knum);
        for(int i=0;i<a.size();i++){
            int x = a[i]+knum[i]+carry;
            ans.push_back(x%10);
            carry = x/10;
        }
        for(int i=a.size();i<knum.size();i++){
            int x = knum[i]+carry;
            ans.push_back(x%10);
            carry = x/10;
        }
        if(carry)ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};