class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int answer = 1;
        while(!st.empty()&&st.top().first<=price){
            answer += st.top().second;
            st.pop();
        }
        st.push({price,answer});
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */