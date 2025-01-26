class MinStack {
public:
    map<int,int> m;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        m[val]++;
    }
    
    void pop() {
        int peek = st.top();
        m[peek]--;
        if(m[peek]==0) m.erase(peek);
        st.pop();
       
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.begin()->first;
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