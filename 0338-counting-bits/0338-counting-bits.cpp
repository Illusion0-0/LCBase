vector<int>preAns(100005,-1);

class Solution {
public:
    string decimalToBinary(int n)
    {
	    string s = bitset<64> (n).to_string();
    	const auto loc1 = s.find('1');
	    if(loc1 != string::npos)
		    return s.substr(loc1);
	    return "0";
    }
    
    void solve(){
        for(int i=0;i<=1e5;i++){
            int one=0;
            string s = decimalToBinary(i);
            for(char c:s)if(c=='1')one++;
            preAns[i]=one;
        }
    }
    
    vector<int> countBits(int n) {
        if(preAns[0]==-1)solve();
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            ans[i]=preAns[i];
        }
        return ans;
    }
};