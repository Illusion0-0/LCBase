class MyHashSet {
public:
    vector<list<int>>v;
    int sz = 1000;
    MyHashSet() {
        v.resize(sz);
    }
    
    void add(int key) {
        if(!contains(key))
            v[key%1000].push_back(key);
    }
    
    void remove(int key) {
        if(contains(key))
        {
            auto i = find(v[key%1000].begin(),v[key%1000].end(),key);
            v[key%1000].erase(i);
        }
    }
    
    bool contains(int key) {
        if(find(v[key%1000].begin(),v[key%1000].end(),key)!=v[key%1000].end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */