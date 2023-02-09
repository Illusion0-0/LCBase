class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
        int low = 0;
        int high = num.size()-1;
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            int l=mid-1, r=mid+1;
            if(l<0)l=INT_MIN; else l=num[l]; // checking mid-1
            if(r>num.size()-1)r=INT_MIN;else r=num[r]; // checking mid+1
            if((l<num[mid]) && (num[mid]>r))return mid;
            else if(num[mid] < r)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};