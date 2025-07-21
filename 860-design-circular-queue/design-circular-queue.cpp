class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int v, Node* n = nullptr, Node* p = nullptr)
        : val(v), next(n), prev(p) {}
};

class MyCircularQueue {
    int space;
    Node* left;   // Sentinel head
    Node* right;  // Sentinel tail

public:
    MyCircularQueue(int k) {
        space = k;
        left = new Node(0);                         // Sentinel left
        right = new Node(0, nullptr, left);         // Sentinel right, prev = left
        left->next = right;                             // Connect left to right
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        Node* newNode = new Node(value, right, right->prev);
        right->prev->next = newNode;
        right->prev = newNode;
        space--;  // Corrected this line
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        Node* toDelete = left->next;
        left->next = toDelete->next;
        toDelete->next->prev = left;
        delete toDelete;  // Avoid memory leak
        space++;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : left->next->val;
    }

    int Rear() {
        return isEmpty() ? -1 : right->prev->val;
    }

    bool isEmpty() {
        return left->next == right;
    }

    bool isFull() {
        return space == 0;
    }

    ~MyCircularQueue() {
        // Free memory of all nodes
        while (!isEmpty()) {
            deQueue();
        }
        delete left;
        delete right;
    }
};
