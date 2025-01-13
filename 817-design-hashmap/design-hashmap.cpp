class MyHashMap {
public:
    vector<int> myhash;
    MyHashMap() {
        myhash.resize(1e6+1,-1);
    }
    
    void put(int key, int value) {
        myhash[key] = value;
    }
    
    int get(int key) {
        return myhash[key];
    }
    
    void remove(int key) {
         myhash[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */