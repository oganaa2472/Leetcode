class MyHashSet {
public:
    vector<bool> myhash;
    MyHashSet() {
      myhash.resize(1e6+1);
    }
    
    void add(int key) {   
        myhash[key] = true;
    }
    
    void remove(int key) {
        myhash[key] = false;
    }
    
    bool contains(int key) {
        return myhash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */