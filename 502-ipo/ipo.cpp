class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
    
        // Store projects as pairs: {capital, profit}
        vector<pair<int,int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Min-heap by capital requirement
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minCapitalHeap;
        for (auto &p : projects) minCapitalHeap.push(p);
        priority_queue<int> maxProfitHeap;
        for (int i = 0; i < k; i++) {
        // Move all projects affordable with current capital to maxProfitHeap
        while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= W) {
            maxProfitHeap.push(minCapitalHeap.top().second);
            minCapitalHeap.pop();
        }
        
        if (maxProfitHeap.empty()) break; // No project can be done
        
        // Pick the most profitable project
        W += maxProfitHeap.top();
        maxProfitHeap.pop();
    }
    
    return W;

  
    }
};