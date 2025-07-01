class FreqStack {
public:
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> stacks;
    int maxCnt;

    FreqStack() {
        maxCnt = 0;
    }
    
    void push(int val) {
        int valCnt = cnt[val]++;
        if(valCnt>maxCnt){
            maxCnt = valCnt;
            stacks[valCnt] = stack<int>();
        }
        stacks[valCnt].push(val);
      
    }
    int pop() {
        int res = stacks[maxCnt].top();
        stacks[maxCnt].pop();
        cnt[res]--;
        if(stacks[maxCnt].empty()){
            maxCnt--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */