class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26]{0};
        for(char c:magazine)mag[c-'a']++;
        for(char c:ransomNote)
            if(--mag[c-'a']<0)
                    return false;
        return true;
        
        
    }
};