class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        // Relaxation for at most k + 1 times
        for (int i = 0; i <= k; ++i) {
            vector<int> temp(cost);
            for (auto &flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if (cost[u] != INT_MAX) {
                    temp[v] = min(temp[v], cost[u] + w);
                }
            }
            cost = temp;
        }
        
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};