class MinStack {
public:
    stack<int> minStack;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty()||val<=minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        int temp = st.top();
        st.pop();
        if(temp==minStack.top()){
            minStack.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */