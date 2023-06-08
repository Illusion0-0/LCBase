class DetectSquares {
public:
    map<vector<int>,int> m;
    DetectSquares() {
        m.clear();
    }
    
    void add(vector<int> point) {
        m[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int ans=0;
        for(auto &i:m)
        {
            int x2 = i.first[0];
            int y2 = i.first[1];
            int a2 = m[{x2,y2}];
            if(y2==y1)
            {
                int len = abs(x1-x2);
                int cntp1=0,cntp2=0,cntn1=0,cntn2=0;
                for(auto &j:m)
                {
                    int x3 = j.first[0];
                    int y3 = j.first[1];
                    if(x3==x1 && y3>y1 && y3-y1==len)
                    {
                        cntp1+=m[{x3,y3}];
                    }
                    if(x3==x2 && y3>y1 && y3-y1==len)
                    {
                        cntp2+=m[{x3,y3}];
                    }
                }
                ans+=cntp1*cntp2*a2;
                for(auto &j:m)
                {
                    int x3 = j.first[0];
                    int y3 = j.first[1];
                    if(x3==x1 && y1>y3 && y1-y3==len)
                    {
                        cntn1+=m[{x3,y3}];
                    }
                    if(x3==x2 && y1>y3 && y1-y3==len)
                    {
                        cntn2+=m[{x3,y3}];
                    }
                }
                ans+=cntn2*cntn1*a2;
            }
        }
        return ans;
    }
};