struct Node {
    int key, val;
    Node* next;

    Node(int k) : key(k), val(-1), next(nullptr) {}
    Node(int k, int v) : key(k), val(v), next(nullptr) {}
};

class MyHashMap {
    vector<Node*> map;

    int hash(int key) {
        return key % map.size();
    }

public:
    MyHashMap() {
        map.resize(10000);
        for (auto& bucket : map) {
            bucket = new Node(0);
        }
    }

    void put(int key, int value) {
        Node* cur = map[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }
        cur->next = new Node(key, value);
    }

    int get(int key) {
        Node* cur = map[hash(key)]->next; // skip dummy
        while (cur) {
            if (cur->key == key) return cur->val;
            cur = cur->next;
        }
        return -1;
    }

    void remove(int key) {
        Node* cur = map[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                Node* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
                return;
            }
            cur = cur->next;
        }
    }
};
