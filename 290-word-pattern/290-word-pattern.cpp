class Solution {
public:
    bool wordPattern(string pattern, string s) {
  map<char, int> m;
  map<string, int> mm;
  int k = 1;
  vector<int> v, vv;
  for (char i : pattern) {
    if (m[i] == 0) {
      m[i] = k;
      k++;
    }
  }
  k = 1;
  string ss = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ' && ss!="") {
      if(mm[ss]==0){
      cout << ss << " " << k << "\n";
      mm[ss] = k;
      k++;
      }
			ss.clear();
    } 
    else
      ss.push_back(s[i]);
  }
  cout << endl;
  if(mm[ss]==0) mm[ss]= k;
  for (int i = 0; i < pattern.length(); i++) {
    v.push_back(m[pattern[i]]);
    cout << v[i] << " ";
  }
  ss = "";
  cout << endl;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      vv.push_back(mm[ss]);
      ss = "";
    } else
      ss += s[i];
  }
  vv.push_back(mm[ss]);
  for (int i : vv) cout << i << " ";
  return v == vv;
    }
};