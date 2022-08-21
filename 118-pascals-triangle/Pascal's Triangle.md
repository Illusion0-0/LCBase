https://leetcode.com/problems/pascals-triangle/


1. **Approach 1**: Simple Brute

```cpp
vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec;
        int i=2,val=1;
        vector<int>temp;
        temp.push_back(1),vec.push_back(temp),temp.push_back(1);
        vec.push_back(temp),temp.clear();
        if(numRows==1)return {{1}};
        else{
        numRows-=2;
        while(numRows--){
            temp.push_back(1);
            for(int j=0;j<vec[i-1].size()-1;j++){
                temp.push_back(vec[i-1][j]+vec[i-1][j+1]);
            }
            temp.push_back(1);
            vec.push_back(temp);
            temp.clear();
            i++;
        }
        return vec;
        }
    }
```

```text
Time Complexity: O(n^2)
Space Complexity: O(n^2)
```

2. **Approach 2:**  Using Factorial nCr (Learned how to calculate nCr of big numbers).

```cpp
	int ncr(int n, int r){
        long long ans=1;
        for (int i = 1; i <= r; i++) {
            ans *= (n - r )+ i;
            ans /= i;
        }
        return ans;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v(numRows);
        v[0]={1};
        for(int i=1;i<numRows;i++){
            vector<int>k;
            for(int j=0;j<=i;j++){
                k.push_back(ncr(i,j));
            }
            v[i] = k;
            k.clear();
        }
        return v;
    }
```

```text
Time Complexity: O(n^3)
Space Complexity: O(n^2)
```