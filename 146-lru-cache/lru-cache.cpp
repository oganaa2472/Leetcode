class Node {
public:
    int key;
    int data;
    Node* next;
    Node* prev;
    
    Node(int key, int val) {
        this->key = key;
        this->data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> lru;
    int capacity;
    Node* left;  // dummy head
    Node* right; // dummy tail

    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    // Remove a node from the list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // Insert node before right (most recent)
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

    int get(int key) {
        if (lru.count(key)) {
            Node* node = lru[key];
            remove(node);
            insert(node);
            return node->data;
        }
        return -1;
    }

    void put(int key, int value) {
        if (lru.count(key)) {
            remove(lru[key]);
            delete lru[key];
        }
        Node* newNode = new Node(key, value);
        lru[key] = newNode;
        insert(newNode);

        if (lru.size() > capacity) {
            Node* least = left->next;
            remove(least);
            lru.erase(least->key);
            delete least;
        }
    }
};
