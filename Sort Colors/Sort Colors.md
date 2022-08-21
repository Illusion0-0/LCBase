[Sort Colors](https://leetcode.com/problems/sort-colors/) [Dutch partitioning problem](https://en.wikipedia.org/wiki/Dutch_national_flag_problem)

1.  Direct Implementation { Counting Sort }

```cpp
void sortColors(vector<int>& nums) {
        int n = nums.size();
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)a++;
            else if(nums[i]==1)b++;
            else c++;
        }
        int k=0;
        for(int i=0;i<a;i++,k++){
            nums[k]=0;
        }
        for(int i=0;i<b;i++,k++){
            nums[k]=1;
        }
        for(int i=0;i<c;i++,k++){
            nums[k]=2;
        }
}
```

```text
Time Complexity: O(n)
Space Complexity: O(1)
```

2. **Follow Up:**  TWO POINTER 1-Pass solution { Uses approach of Dutch Partitioning Problem }

```cpp
void sortColors(vector<int>& nums) {
        int red=0, white=0, blue = nums.size()-1;
        while (white <= blue){
            if (nums[white] == 0){
                swap(nums[red], nums[white]);
                white += 1;
                red += 1;
            }
            else if (nums[white] == 1)
                white += 1;
            else{
                swap(nums[white], nums[blue]);
                blue -= 1;
            }
        }
        
    }
```

> Got to know about **One-Pass**: Reading or working on input items only once.