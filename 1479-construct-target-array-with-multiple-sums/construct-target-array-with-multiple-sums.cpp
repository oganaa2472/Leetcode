class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
    priority_queue<long long> pq;
    
    for (int x : target) {
        sum += x;
        pq.push(x);
    }
    
    while (pq.top() > 1) {
        long long maxVal = pq.top(); pq.pop();
        long long rest = sum - maxVal;
        
        if (rest == 0) return false; 
        if (rest == 1) return true;  
        
        long long prev = maxVal % rest;
        if (prev == 0 || prev == maxVal) return false;
       
        sum = rest + prev;
        pq.push(prev);
    }
    
    return true;
    }
};