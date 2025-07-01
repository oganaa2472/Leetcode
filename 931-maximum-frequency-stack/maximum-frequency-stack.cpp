class FreqStack {
public:
    priority_queue<vector<int>> heap; // freq,index,val

    unordered_map<int, int> cnt;
    int index;
    FreqStack() {
        index = 0;
    }
    
    void push(int val) {
        cnt[val]++;
        heap.push({cnt[val],index++,val});
    }
    int pop() {
        auto top = heap.top();
        heap.pop();
        int val = top[2];
        cnt[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */