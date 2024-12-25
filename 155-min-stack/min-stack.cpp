class MinStack {
public:
    stack<int> st;
    map<int,int> mp; 
    MinStack() {
        mp.clear();
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        int a = st.top();
        st.pop();
        if(mp[a]==1) mp.erase(a);
        else mp[a]--;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mp.begin()->first;
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