class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<vector<int>>mid=triplets, right=triplets;
        for(auto &i:mid)   swap(i[0],i[1]);
        for(auto &i:right) swap(i[0],i[2]);
        int l = target[0], m = target[1], r = target[2];
        int x,y,z; x=y=z=-1;
        for(int i=0;i<n;i++){
            if(triplets[i][1]<=m && triplets[i][2]<=r && triplets[i][0]==l){x=i;break;}
        }
        for(int i=0;i<n;i++){
            if(mid[i][1]<=l && mid[i][2]<=r && mid[i][0]==m){y=i;break;}
        }
        for(int i=0;i<n;i++){
            if(right[i][1]<=m && right[i][2]<=l && right[i][0]==r){z=i;break;}
        }
        if(x<0 || y<0 || z<0)return false;
        return true;
    }
};