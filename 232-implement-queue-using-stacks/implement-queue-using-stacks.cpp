class MyQueue {
public:
    stack<int> st;

    MyQueue() {
        
    }
    
    void push(int x) {
       
        stack<int> st1;
        while(!st.empty()){
            int peek = st.top();
            st1.push(peek);
            st.pop();
        }
        st.push(x);
        while(!st1.empty()){
            int peek = st1.top();
            st.push(peek);
            st1.pop();
        }
        
    }
    int pop() {
        if(empty()) return -1;
        int top = st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */