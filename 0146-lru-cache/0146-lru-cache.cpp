class LRUCache {
public:
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>addr;
    int maxsz=0,cap=0;
    list<pair<int,int>>::iterator left, right;
    LRUCache(int capacity) {
        cap=capacity;
        l.push_front({-2,-2});
        l.push_back({-1,-1});
        left=l.begin();
        right=--l.end();
    }
    
    int get(int key) {
        if(addr.find(key)!=addr.end()){
            int val = (*addr[key]).second;
            l.erase(addr[key]);
            l.push_back({key,val});
            right=--l.end();
            addr[key]=right;
            return (*right).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
      if (addr.find(key) != addr.end()) {
        l.erase(addr[key]);
        addr.erase(key);
        maxsz--;
      }
      right=--l.end();
      // insert at right (MRU)
      if ((*right).first < 0) {
        l.erase(right);
        right = --l.end();
      }
      l.push_back({key, value});
      right = --l.end();
      addr[key] = right;
      maxsz++;
      if (maxsz > cap) {
        // remove LRU from left
        left = l.begin();
        if ((*left).first < 0) {
          l.erase(left);
          left = l.begin();
        }
        left = l.begin();
        addr.erase((*left).first);
        l.erase(left);
        left = l.begin();
        maxsz--;
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */