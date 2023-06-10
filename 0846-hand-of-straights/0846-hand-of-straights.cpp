class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        unordered_map<int,int>m;
        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }
        for(int i=0;i<hand.size();i++){
            if(!m[hand[i]]) continue;
            int curr = hand[i];
            for(int j=curr;j<curr+groupSize;j++){
                if(!m[j]){cout<<curr<<" ";return false;}
                m[j]--;
            }
        }
        return true;
    }
};