[Next Permutation](https://leetcode.com/problems/next-permutation/)

1.  Thought O(n^2) approach because n = 100 which was bad, I should have thought of better solution.

```cpp
void nextPermutation(vector<int> &nums)
    {
        int pos=0,n=-1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int x = nums[i];
            n=-1;
            for (int j = i+1; j < nums.size(); j++)
            {
                // cout << x<<":"<<nums[j] << " ";
                if (nums[j]>x)
                {
                    if(n==-1)n=nums[j];
                    else n = min(nums[j],n);
                }  
            }
            if(n!=-1){
                pos=i;break;
            }
        }
        cout<<endl;
        for (int i = pos+1; i < nums.size(); i++)
        {
            if(nums[i]==n){
                swap(nums[i],nums[pos]);
                sort(nums.begin()+pos+1,nums.end());
                break;
            }
        }
        if(n==-1)sort(nums.begin(),nums.end());
        
        for (auto i : nums)
            cout << i << " ";
    }
```

```text
Time Complexity: O(n^2)
Space Complexity: O(1)
```

2.  Thought O(n*log(n)) in two ways

```cpp
void nextPermutation(vector<int> &nums)
    {
        int pos=-1,n=-1;
        for (int i = nums.size() - 1; i > 0; i--) 
        {
            if(nums[i-1]<nums[i]){
                pos=i-1;
                break;
            }
        }
        if(pos!=-1){
        int x = nums[pos];
        sort(nums.begin()+pos+1,nums.end());
        int ind = upper_bound(nums.begin()+pos+1,nums.end(),x)-nums.begin();
        if(ind!=nums.size()){
            swap(nums[pos],nums[ind]);
        }
        sort(nums.begin() + pos + 1, nums.end());
        }
        else sort(nums.begin(),nums.end());
        for (auto i : nums)
            cout << i << " ";
    }
```

```cpp
void nextPermutation(vector<int> &nums)
    {
        int pos=-1,n=-1;
        for (int i = nums.size() - 1; i > 0; i--) 
        {
            if(nums[i-1]<nums[i]){
                pos=i-1;
                break;
            }
        }
        if(pos!=-1){
        int x = nums[pos],pos2=-1;
        for (int i = pos+1; i < nums.size(); i++)
        {
            if(nums[i]>x){
                if(n==-1)n=nums[i];
                else n = min(n,nums[i]);
                pos2=i;
            }
        }
        
        if(n!=-1){
            swap(nums[pos],nums[pos2]);
        }
        sort(nums.begin() + pos + 1, nums.end());
        }
        else sort(nums.begin(),nums.end());
        for (auto i : nums)
            cout << i << " ";
    }
```

3.  In the above code, sort is using O(n*log(n)) which can be replaced by **reverse** taking O(n) time 

```cpp
void nextPermutation(vector<int> &nums)
    {
        int pos=-1,n=-1;
        for (int i = nums.size() - 1; i > 0; i--) 
        {
            if(nums[i-1]<nums[i]){
                pos=i-1;
                break;
            }
        }
        if(pos!=-1){
        int x = nums[pos],pos2=-1;
        for (int i = pos+1; i < nums.size(); i++)
        {
            if(nums[i]>x){
                if(n==-1)n=nums[i];
                else n = min(n,nums[i]);
                pos2=i;
            }
        }
        
        if(n!=-1){
            swap(nums[pos],nums[pos2]);
        }
        reverse(nums.begin() + pos + 1, nums.end());
        }
        else reverse(nums.begin(),nums.end());
        for (auto i : nums)
            cout << i << " ";
    }
```

```text
Time Complexity: O(n)
Space Complexity: O(1)
```

> In CP directly use **next_permutation(nums);** works in O(n) only.