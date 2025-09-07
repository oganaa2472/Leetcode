class MinStack {
public:
    stack<int> st;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }else{
            int top = minStack.top();
            int minEl = min(val,top);
            minStack.push(minEl);
        }
    }
    
    void pop() {
        minStack.pop();
        st.pop();
        
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