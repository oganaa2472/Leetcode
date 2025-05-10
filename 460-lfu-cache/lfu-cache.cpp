class Node{
    public:
    Node* next;
    Node* prev;
    int key;
    int val;
    int cnt;
    Node(int k,int v){
        next=nullptr;
        prev=nullptr;
        key = k;
        val = v;
        cnt = 1;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
    int size;
    List(){
        head =new Node(0,0);
        tail =new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    void remove(Node* node){
        Node* next = node->next;
        Node* prev = node->prev;
        prev->next = next;
        next->prev = prev;
        size--;
    }
};
class LFUCache {
public:

    unordered_map<int,Node*> cache;
    unordered_map<int,List*> freqList;
    int curSize = 0;
    int minFreq;
    int capacity;
    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
        minFreq = 0;
    }
    void updateNode(Node* node){
        cache.erase(node->key);
        freqList[node->cnt]->remove(node);
        if(node->cnt==minFreq&&freqList[node->cnt]->size==0){
            minFreq++;
        }
        List* nextHighFreq = new List();
        if(freqList.find(node->cnt+1)!=freqList.end()){
            nextHighFreq = freqList[node->cnt+1];
        }
        node->cnt+=1;
        nextHighFreq->addFront(node);
        freqList[node->cnt] = nextHighFreq;
        cache[node->key] = node;
    }
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        Node* cur = cache[key];
        int val = cur->val;
        updateNode(cur);
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (cache.find(key) != cache.end()) {
            Node *node = cache[key];
            node->val = value;
            updateNode(node);
        }
        else {
            if(curSize==capacity){
                List* list = freqList[minFreq];
                cache.erase(list->tail->prev->key);
                freqList[minFreq]->remove(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* list = new List();
            if(freqList.find(minFreq)!=freqList.end()){
                list = freqList[minFreq];
            }
            Node* n = new Node(key,value);
            list->addFront(n);
            cache[key] = n;
            freqList[minFreq] = list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */