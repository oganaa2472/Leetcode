class Node {
    public:
        string url;
        Node* next;
        Node* prev;
        Node(string u){
            url = u;
            next = nullptr;
            prev= nullptr;
        }
};
class BrowserHistory {
    
public:
    Node* cur;
    BrowserHistory(string homepage) {
        cur =new Node(homepage);
    }
    
    void visit(string url) {
        Node* newTab =new Node(url);
        cur->next = newTab;
        newTab->prev = cur;
        cur = newTab;
    }
    
    string back(int steps) {
        while (cur->prev != NULL && steps-- > 0) {
            cur = cur->prev;
        }
        return cur->url;
    }
    
    string forward(int steps) {
         while (cur->next != NULL && steps-- > 0) {
            cur = cur->next;
        }
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */