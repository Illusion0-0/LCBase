class Solution {
public:
    int add(int x,int y, int carry){
        if(x==y && x==1)return (carry?11:10);
        else if(x==y && x==0)return (carry?1:0);
        else return (carry?10:1);
    }
    
    string addBinary(string a, string b) {
        int carry = 0;
        string ans = "";
        if(a.size()>b.size())swap(a,b);
        int j = j = b.size()-1;
        for(int i=a.size()-1;i>=0;i--,j--){
            int x = a[i]-'0', y = b[j]-'0';
            int num = add(x,y,carry);
            cout<<num<<" ";
            carry = num/10;
            ans+=to_string(num%10);
        }
        for(int i=j;i>=0;i--){
            int x = carry, y = b[i]-'0';
            int num = add(x,y,0);
            carry = num/10;
            ans+=to_string(num%10);
        }
        if(carry)ans+=to_string(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};