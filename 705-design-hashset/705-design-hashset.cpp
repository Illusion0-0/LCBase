class MyHashSet {
public:
    vector<list<int>>v;
    int sz = 100;
    MyHashSet() {
        v.resize(sz);
    }
    
    void add(int key) {
        if(!contains(key))
            v[key%100].push_back(key);
    }
    
    void remove(int key) {
        if(contains(key))
        {
            auto i = find(v[key%100].begin(),v[key%100].end(),key);
            v[key%100].erase(i);
        }
    }
    
    bool contains(int key) {
        if(find(v[key%100].begin(),v[key%100].end(),key)!=v[key%100].end()) return true;
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