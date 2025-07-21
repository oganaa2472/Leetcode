class Node{
    public:
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int k,int v){
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
};
class LRUCache {
public:
    Node* left;
    Node* right;
    int capacity;

    // right most recently
    // left least recently
    unordered_map<int,Node*> cache;
    LRUCache(int capacity) {
        left = new Node(0,0);
        right = new Node(0,0);
        this->capacity = capacity;
        left->next = right;
        right->prev = left;
    }
    void remove(Node* n){
        Node* l = n->prev;
        Node* r = n->next;
        l->next = r;
        r->prev = l;
    }
    void insert(Node* n){
        Node* prev = right->prev;
        prev->next = n;
        n->prev = prev;
        n->next = right;
        right->prev = n;

    }
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* n = cache[key];
            remove(n);
            insert(n);
            return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }

        Node* newNode = new Node(key,value);
        insert(newNode);
        cache[key] = newNode;
        if(capacity<cache.size()){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */