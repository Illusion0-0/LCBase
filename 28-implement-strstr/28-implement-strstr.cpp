class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length(), h = haystack.length();
        int k=0,pos=-1;
        for(int i=0;i<h;i++){
            if(haystack[i]==needle[k]){
                pos=i;
                k++;
                if(k==n)return (pos-n)+1;
            }else{
                i=i-k;
                k=0;
            }
        }
        return -1;
    }
};