int myCompare(string X, string Y){ return X+Y>Y+X; }
class Solution {
public:
 
    string printLargest(vector<string> arr)
    {
        string ans="";
        sort(arr.begin(), arr.end(), myCompare);
        if(arr[0][0]=='0')return "0";
        for (int i = 0; i < arr.size(); i++)
            ans+=arr[i];
        return ans;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string>ok;
        for(int i:nums)ok.push_back(to_string(i));
        return printLargest(ok);
    }
};