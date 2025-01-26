class MyStack {
public:
    queue<int> q;
// empty
// size
// front
// back
// push_back
// pop_front
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size()-1;
        for(int i = 0;i<size;i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */