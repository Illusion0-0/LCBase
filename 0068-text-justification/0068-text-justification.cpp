class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curr= 0;
        vector<string> ans;
        while(curr < words.size())
        {
            // stage 1
            int e=curr, l = words[e].length();
            for(int t= e+1; t<words.size(); t++)
            {
                l+=words[t].length();
                if((maxWidth-l)>=t-curr)
                    e = t;
                else
                {
                    l-=words[t].length();
                    break;
                }
            }
            // stage 2
            string line, space; 
            int x= 1, y=0;
            if(e - curr && e!=words.size()-1)
            {
               x = (maxWidth-l)/(e-curr);
               y = (maxWidth-l)%(e-curr);
            }
            while(x--)
                space+=" ";
            for(;curr <= e; curr++)
            {
                line+=words[curr];
                if(curr!=e)
                  line+=space;
                if(y)
                {
                    line+=" ";
                    y--;
                }
            }
            while(line.length()<maxWidth)
                line+=" ";
            ans.push_back(line);
        }
        return ans;
    }
};