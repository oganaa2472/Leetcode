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
    Node* head;
    Node* tail;
    unordered_map<int,Node*> cache; 
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
       
    }
    void add(Node* node){
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev; 
        node->next = tail;
        tail->prev = node;
    }
    int get(int key) {
        if(cache.count(key)){
            Node* cur = cache[key];
            remove(cur);
            add(cur);
            return cur->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
       
        if(cache.count(key)){
            Node* cur = cache[key]; 
            remove(cur);
            // delete cache[key];
        }
        Node* node = new Node(key,value);
        add(node);
        cache[key] = node;
        if(capacity<cache.size()){
            Node* lst = head->next;
            cache.erase(lst->key);
            remove(lst);
            // delete lst;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */