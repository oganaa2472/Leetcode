class LRUCache {
private:
    int capacity;
    list<pair<int, int>> lruList; // Stores (key, value)
    unordered_map<int, list<pair<int, int>>::iterator> cache; // key -> node

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // Move the accessed node to front
        auto node = cache[key];
        int val = node->second;
        lruList.erase(node);
        lruList.push_front({key, val});
        cache[key] = lruList.begin();
        return val;
    }

    void put(int key, int value) {
        // Key already exists: remove old
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
        }
        // Cache full: remove LRU
        else if (lruList.size() == capacity) {
            int lruKey = lruList.back().first;
            lruList.pop_back();
            cache.erase(lruKey);
        }

        // Insert new (key, value) at front
        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }
};
