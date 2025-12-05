struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; // Most recently used
    Node* tail;
     void remove(Node* node) {
        if (!node) return;
        if (node->prev) node->prev->next = node->next;
        else head = node->next; // node was head

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev; // node was tail
    }
    // Add node at head
    void addToHead(Node* node) {
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
    }
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        remove(node);
        addToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            addToHead(node);
        } else {
            Node* node = new Node(key, value);
            if (cache.size() >= capacity) {
                // Remove LRU
                cache.erase(tail->key);
                remove(tail);
            }
            addToHead(node);
            cache[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */