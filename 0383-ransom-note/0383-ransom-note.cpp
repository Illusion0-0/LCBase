class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mag,ransom;
        for(char c:magazine)mag[c]++;
        for(char c:ransomNote)ransom[c]++;
        for(char c:ransomNote)if(mag[c]<ransom[c])return false;
        return true;
        
        
    }
};