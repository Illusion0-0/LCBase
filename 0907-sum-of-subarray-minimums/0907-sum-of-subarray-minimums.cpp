class Solution {
public:
    //--------------------------------Code for mod-----------------------------------------------
    const long mod = 1e9+7;
    int add(int a, int b) { return ((a % mod) + (b % mod)) % mod; }
    int sub(int a, int b) { return ((a % mod) - (b % mod) + mod) % mod; }
    int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
    //--------------------------------Code for mod-----------------------------------------------
    
    int sumSubarrayMins(vector<int>& arr) {
        //--------------------------------Code for histogram begins------------------------------
        int n = arr.size();
        vector<int>left(n,0),right(n,0);
        stack<int>s;
        map<int,int>m;
        for(int i=0;i<n;i++){
            int lmin=-1;
            m[arr[i]]++;
            while(!s.empty() && m[arr[i]]==0 && arr[i]<=arr[s.top()]){
                lmin=s.top();
                s.pop();
            }
            while(!s.empty() && m[arr[i]] && arr[i]<arr[s.top()]){
                lmin=s.top();
                s.pop();
            }
            if(!s.empty())lmin=s.top();
            else lmin=-1;
            s.push(i);
            left[i]=lmin;
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            int rmin=n-1;
            while(!s.empty() && arr[i]<=arr[s.top()]){
                rmin=s.top()-1;
                s.pop();
            }
            if(!s.empty())rmin=s.top()-1;
            else rmin=n-1;
            s.push(i);
            right[i]=rmin;
        }
        //--------------------------------Code for histogram ends-------------------------------
        
        
        //------------------------------Code for this problem begins----------------------------
        int ans=0;
        for(int i=0;i<n;i++){
            int r = right[i], l = left[i], v = arr[i];
            if(i-l==1 || i-l==(r-l)){
                int a = sub(r,l), b = mul(a,v);
                ans = add(ans , b);
            }
            else{
                int a = sub(i,l), b = sub(r,i);
                int k = mul(a,v), c = add(b,1);
                int d = mul(k,c);
                ans = add(ans , d);
            }
        }
        return ans%mod;
        //--------------------------------Code for this problem ends----------------------------
    }
};