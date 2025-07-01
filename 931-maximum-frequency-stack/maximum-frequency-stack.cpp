class FreqStack {
public:
    unordered_map<int, int> cnt;
    vector<int> stack;
    FreqStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        cnt[val]++;
    }
    int pop() {
        int maxCnt = 0;
        for (auto& [_, frequency] : cnt) {
            maxCnt = max(maxCnt, frequency);
        }
        int i = stack.size()-1;
        while (cnt[stack[i]] != maxCnt) {
            i--;
        }
        int val = stack[i];
        stack.erase(stack.begin()+i);
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