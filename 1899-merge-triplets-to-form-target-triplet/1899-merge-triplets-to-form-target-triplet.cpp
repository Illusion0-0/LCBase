class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int l = target[0], m = target[1], r = target[2];
        int x,y,z; x=y=z=-1;
        for(int i=0;i<n;i++){
            if(triplets[i][1]<=m && triplets[i][2]<=r && triplets[i][0]==l)x=i;
            if(triplets[i][1]==m && triplets[i][2]<=r && triplets[i][0]<=l)y=i;
            if(triplets[i][1]<=m && triplets[i][2]==r && triplets[i][0]<=l)z=i;
        }
        if(x<0 || y<0 || z<0)return false;
        return true;
    }
};