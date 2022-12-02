class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int start=0, end=n-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if((mid+1<n && arr[mid]>arr[mid+1]) && (mid-1>=0 && arr[mid]>arr[mid-1]))return mid;
            else if((mid-1>=0 && arr[mid-1]<arr[mid])||(mid+1<n && arr[mid]<arr[mid+1]))start=mid+1;
            else end=mid-1;
        }
        return arr.size()-1;
    }
};