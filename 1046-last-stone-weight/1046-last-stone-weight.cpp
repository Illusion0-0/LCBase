class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int,greater<int>>m;
        for(int i:stones) m.insert(i);
        while(m.size()>1){
            int a = *m.begin(), b = *(++m.begin());
            m.erase(m.begin());
            m.erase(m.begin());
            if(a!=b)m.insert(abs(a-b));
        }
        if(m.size())return *m.begin();
        else return 0;
    }
};