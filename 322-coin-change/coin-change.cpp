class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
          if (amount == 0) return 0;

    queue<pair<int, int>> q; // {current sum, steps}
    unordered_set<int> visited;
    
    q.push({0, 0});
    visited.insert(0);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        for (int coin : coins) {
            int nxt = current + coin;
            if (nxt == amount) return steps + 1;
            if (nxt < amount && visited.find(nxt) == visited.end()) {
                visited.insert(nxt);
                q.push({nxt, steps + 1});
            }
        }
    }

    return -1;
    }
};